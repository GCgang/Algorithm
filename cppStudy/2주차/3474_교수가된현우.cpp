// https://www.acmicpc.net/problem/3474
/*
문제:
N!이 얼마나 큰지 대략적으로나마 알려주기 위해,
자연수 N이 주어지면 N!의 오른쪽 끝에 있는 0의 개수를 알려주는 프로그램을 작성하시오

입력:
첫째 줄에 테스트 케이스의 개수 T가 주어지고,
이어서 T개의 줄에 정수 N이 주어진다(1 <= N <= 1000000000)

출력:
각 줄마다 N!의 오른쪽 끝에 있는 0의 개수를 출력한다

ex:
입력
6
3
60
100
1024
23456
8735373

출력
0
14
24
253
5861
2183837
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N;

    cin >> T;
    while (T--)
    {
        cin >> N;

        int two = 0, five = 0;
        for (int i = 2; i <= N; i *= 2)
        {
            two += N / i;
        }
        for (int j = 5; j <= N; j *= 5)
        {
            five += N / j;
        }
        cout << min(two, five) << "\n";
    }
    return 0;
}