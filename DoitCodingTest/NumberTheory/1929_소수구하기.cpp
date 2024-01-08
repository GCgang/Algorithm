// https://www.acmicpc.net/problem/1929
/*
문제:
M 이상 N 이하의 소수를 모두 출력하는 프로그램을 작성하시오

입력:
1번째 줄에 자연수 M과 N이 빈칸을 사이에 두고 주어진다
(1 <= M <= N <= 1,000,000)
M이상 N이하의 소수가 1개 이상 있는 입력만 주어진다

출력:
1줄에 1개씩, 증가하는 순서대로 소수를 출력한다

ex:
입력        출력
3 16        3
            5
            7
            11
            13
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;

    cin >> M >> N;
    vector<int> A(N + 1);

    for (int i = 2; i <= N; ++i)
    {
        A[i] = i;
    }
    for (int i = 2; i <= sqrt(N); ++i) // 제곱근까지
    {
        if (A[i] == 0)
            continue ;
        for (int j = i + i; j <= N; j += i) // 배수 지우기
            A[j] = 0;
    }
    for (int i = M; i <= N; ++i)
    {
        if (A[i] != 0)
            cout << A[i] << "\n";
    }
    return 0;
}