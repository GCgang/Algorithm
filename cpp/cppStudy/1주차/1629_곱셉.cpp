#include <iostream>
using namespace std;
// 자연수 A를 B번 곱한 수를 알고 싶다
// 단, 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하라

// 입력
// A, b, C (2147483647 이하의 자연수)

// 출력
// A를 B번 곱한 수를 C로 나눈 나머지를 출력

// ex)
// 입력: 10 11 12 
// 출력: 4

// 아이디어
// 예를들어 2^8은 2^4 X 2^4와 같다고 할 수 있는데 2x2x2x2.... X 2x2x2x2... 하지 않고,
// 어떠한 변수 A에 담아 놓는다면 A X A로 연산량을 줄일 수 있다

// 모듈러 연산
// (a + b) % c = (a % c + b % c) % c 그리고 (a * b) % c = (a % c * b % c) % c 


long long modRecursive(long long A, long long B, long long C)
{
    // 기저 조건 
    if (B == 1)
        return (A % C);

    long long res = modRecursive(A, B/2, C);

    res = (res * res) % C;
    // 홀수 의 경우 (2^5 == 2^2 x 2^2 x 2^1) 한번 더 곱해준다
    if (B % 2)
        res = (res * A) % C;
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B, C;

    cin >> A >> B >> C;

    cout << modRecursive(A, B, C) << "\n";
    return (0);
}
