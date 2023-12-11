// https://www.acmicpc.net/problem/2750
/*
문제:
N개의 수가 주어졌을 떄 이를 오름차순 정렬하는 프로그램을 작성하시오

입력:
1번째 줄에 수의 개수 N(1 <= N <= 1,000), 2번째 줄부터 N개의 줄에 숫자가 주어진다.
이 수는 절대값이 1,000보다 작거나 같은 정수다. 수는 중복되는 않는다

출력:
1번째 줄부터 N개의 줄에 오름차순 정렬한 결과를 1줄에 1개씩 출력한다

ex:
입력            출력
5 // 수의 개수     1
5                2
2                3
3                4
4                5
1
*/
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int numArray[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> numArray[i];
    }

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - 1 - i; ++j)
        {
            if (numArray[j] > numArray[j + 1])
            {
                swap(numArray[j], numArray[j + 1]);
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << numArray[i] << '\n';
    }
    return 0;
}