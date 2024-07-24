// https://www.acmicpc.net/problem/1781
/*
문제:
상욱 조교는 동호에게 N개의 문제를 주고서, 각각의 문제를 풀었을 때,
컵라면을 몇 개 줄것인지 제시 하였다.
하지만 동호의 찌를듯한 자신감에 소심한 상욱 조교는 각각의 문제에 대해 데드라인을 정하였다

문제 번호	1	2	3	4	5	6	7
데드라인	1	1	3	3	2	2	6
컵라면 수	6	7	2	1	4	5	1

위와 같은 상황에서 동호가 2, 6, 3, 1, 7, 5, 4 순으로 숙제를 한다면
2, 6, 3, 7번 문제를 시간 내에 풀어 총 15개의 컵라면을 받을 수 있다
문제는 동호가 받을 수 있는 최대 컵라면 수를 구하는 것이다. 위의 예에서는 15가 최대이다
문제를 푸는데는 단위 시간 1이 걸리며, 각 문제의 데드라인은 N이하의 자연수이다.
또, 각 문제를 풀 때 받을 수 있는 컵라면 수와 최대로 받을 수 있는 컵라면 수는 모두 2^31보다 작은 자연수이다

입력:
첫 줄에 숙제의 개수 N(1 <= N <= 200,000)이 들어온다.
다음 줄부터 N+1번째 줄까지 i+1번째 줄에 i번째 문제애 대한 데드라인과
풀면 받을 수 컵라면 수가 공백으로 구분되어 입력된다

출력:
첫 줄에 동호가 받을 수 있는 최대 컵라면 수를 출력한다

ex:
입력
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1

출력
15

1   1   2   2   3   3   6

6   7   4   5   1   2   1
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    vector<pair<int, int> > v;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int deadline, noodleCnt;
    
        cin >> deadline >> noodleCnt;
        v.push_back(make_pair(deadline, noodleCnt));
    }

    // 데드라인을 기준으로 정렬
    sort(v.begin(), v.end());

    int ret = 0;
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < N; ++i)
    {
        pq.push(v[i].second);
        // 만약 데드라인이 1일인데 1일이 3개 있고 3개의 숫자가 주어진다면, 그중 가장 큰 값을 제외하고 모두 pop을 하는 로직
        if (pq.size() > v[i].first)
            pq.pop();
    }

    // 이미 가장 작은 값들은 뺴버렸기 때문에 
    while(!pq.empty())
    {
        ret += pq.top();
        pq.pop();
    }

    cout << ret << "\n";

    return 0;
}