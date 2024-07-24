// https://www.acmicpc.net/problem/4375
/*
문제:
2와 5로 나누어 떨어지지 않는 정수 n(1 <= n <= 10000)가 주어졌을 때,
각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오

입력:
입력은 여러 개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다

출력:
각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다

ex:
입력            출력
3               3
7               6
9901            12 

4는 2의 배수란 말은 4 % 2 == 0 와 같다
ex) 111 % 3 == 0 -> 답은 3

모듈러 법칙
끝에가서 모듈러 연산을 하지않고 그 전단계에서 모듈러 연산을 일일이 해도 결과값은 동일하다
ex) (a+b)%n = (a%n + b%n)%n
ex) (axb)%n = (a%n x b%n)%n
*/

#include <iostream>
using namespace std;

int main()
{
    int N;

    while ((cin >> N))
    {
        if (N % 2 == 0 || N % 5 == 0)
            continue ;

        int number = 1, length = 1;
        while (number % N != 0)
        {
            number = (number * 10 + 1) % N;
            length++;
        }
        cout << length << "\n";
    }
    return 0;
}
