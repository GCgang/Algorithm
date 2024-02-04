// https://www.acmicpc.net/problem/1931
/*
문제:
1개의 회의실에서 N개의 회의를 진행하기 위해 회의실 사용표를 만들려고 한다
각 회의 시작 시간과 끝나는 시간이 주어질 때 회의 시간이 겹치지 않으면서 회의를 가장 많이 진행하려면
최대 몇 번까지 할 수 있는지 알아보자
단, 회의를 시작하면 중간에 중단할 수 없고, 한 회의를 끝내는 것과 동시에 다음 회의를 시작할 수 있다
회의의 시작 시간과 끝나는 시간이 같을 수도 있는데, 이때는 시작하자마자 끝나는 것으로 생각하면 된다

입력:
1번째 줄에 회의의 수 N(1 <= N <= 100,00)
2번째 줄부터 N + 1줄까지는 각 회의의 시작 시간과 끝나는 시간이 공백을 사이에 두고 주어진다
시작 시간관 끝나는 시간은 2^31-1 보다 작거나 같은 자연수 또는 0이다

출력:
1번째 줄에 진행할 수 있는 회의의 최대 개수를 출력한다

ex:
입력            출력   
11              4
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int from, to, n, ret = 1;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    vector<pair<int, int> > v;

    for (int i = 0; i < n; ++i)
    {
        cin >> from >> to;
        // v.push_back({to, from});
        v.push_back(make_pair(to, from));
    }

    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;

    for (int i = 1; i < n; ++i)
    {
        if (v[i].second < to)
            continue;
        from = v[i].second;
        to = v[i].first;
        ret++;
    }

    cout << ret << '\n';

    return 0;
}