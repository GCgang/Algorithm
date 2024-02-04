// https://www.acmicpc.net/problem/2109
/*
문제:
한 저명한 학자에게 n(0 ≤ n ≤ 10,000)개의 대학에서 강연 요청을 해 왔다.
각 대학에서는 d(1 ≤ d ≤ 10,000)일 안에 와서 강연을 해 주면
p(1 ≤ p ≤ 10,000)만큼의 강연료를 지불하겠다고 알려왔다.
각 대학에서 제시하는 d와 p값은 서로 다를 수도 있다.
이 학자는 이를 바탕으로, 가장 많은 돈을 벌 수 있도록 순회강연을 하려 한다.
강연의 특성상, 이 학자는 하루에 최대 한 곳에서만 강연을 할 수 있다.

예를 들어 네 대학에서 제시한 p값이 각각 50, 10, 20, 30이고,
d값이 차례로 2, 1, 2, 1 이라고 하자.
이럴 때에는 첫째 날에 4번 대학에서 강연을 하고,
둘째 날에 1번 대학에서 강연을 하면 80만큼의 돈을 벌 수 있다.

입력:
첫째 줄에 정수 n이 주어진다.
다음 n개의 줄에는 각 대학에서 제시한 p값과 d값이 주어진다.

출력:
첫째 줄에 최대로 벌 수 있는 돈을 출력한다

ex:
입력
7
20 1
2 1
10 3
100 2
8 2
5 20
50 10

출력
185
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int n;
    vector<pair<int, int> > v;
    priority_queue<int, vector<int>, greater<int> > pq;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int pay, day;
    
        cin >> pay >> day;
        v.push_back(make_pair(day, pay));
    }

     // day를 기준으로 오름차순
    sort(v.begin(), v.end());
    
    // 강연을 순회하며 마감일보다 크면 가장 작은 강연료를 뺀다. 예를들어 2일차인데 pq에 3개가 들어가있다면 가장 작은 값을 뺌
    for (int i = 0; i < n; ++i)
    {
        pq.push(v[i].second);
        if(pq.size() > v[i].first)
            pq.pop();
    }

    int ret = 0;
    // 모든 강연료 계산
    while(pq.size())
    {
        ret += pq.top();
        pq.pop();
    }

    cout << ret << "\n";

    return 0;
}