// https://www.acmicpc.net/problem/21921
/*
문제:
X일 동안 가장 많이 들어온 방문자 수와 기간이 몇 개 있는지 구해보자

입력:
1번째 줄에 블로그를 시작하고 지난 일수 N과 X가 공백으로 주어진다
2번째 줄에 블로그 시작 1일차부터 N일차까지 하루 방문자 수가 공백으로 구분되어 주어진다

출력:
첫째 줄에 X일 동안 가장 많이 들어온 방문자 수를 출력한다.
만약 최대 방문자 수가 0이라면 SAD를 출력한다.
만약 최대 방문자 수가 0명이 아닌 경우 둘째 줄에 기간이 몇 개 있는지 출력한다.

제한:
1 <= X <= N <= 250,000
0 <= 방문자 수 <= 8,000

ex:
입력:       출력:
5 2         7
1 4 2 5 1   1
*/


#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, X;

    cin >> N >> X;

    int visit[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> visit[i];
    }

    int sum = 0, max = 0, cnt = 1;

    for (int i = 0; i < X; ++i)
    {
        sum += visit[i];
    }
    max = sum;
    for (int i = 1; i <= N - X; ++i)
    {
        sum +=  visit[i + X - 1] - visit[i - 1];
        if (sum > max)
        {
            max = sum;
            cnt = 1;
        }
        else if (sum == max)
        {
            ++cnt;
        }
    }
    if (max == 0)
    {
        cout << "SAD" << endl;
        return 0;
    }
    cout << max << endl;
    cout << cnt << endl;
    return 0;
}