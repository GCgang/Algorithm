// https://www.acmicpc.net/problem/1202
/*
문제:
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.
상덕이가 털 보석점에는 보석이 총 N개 있다.
각 보석은 무게 Mi와 가격 Vi를 가지고 있다.
상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다
가방에는 최대 한개의 보석만 넣을 수 있다
상더기가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오

입력:
첫 째 줄에 N과 K가 주어진다 (1 <= N, K <= 300,000)
다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다 (0 <= Mi, Vi <= 1,000,000)
다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다 (1 <= Ci <= 1,000,000)
모든 숫자는 양의 정수이다

출력:
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다

ex:
입력
2 1
5 10
100 100
11

출력
10
*/

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    vector<pair<int, int> > v;
    vector<int> bag;

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        int weight, value;

        cin >> weight >> value;
        v.push_back(make_pair(weight, value));
    }
    for (int i = 0; i < K; ++i)
    {
        int weight;

        cin >> weight;
        bag.push_back(weight);
    }

    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());

    int idx = 0;
    long long ret = 0;
    priority_queue<int, vector<int>, less<int> > pq; // 가치가 가장 큰게 맨 위에 올라오는 우선 순위 큐

    for (int i = 0; i < K; ++i)
    {
        // 가방에 넣을 수 있는 보석을 전부 넣는데 가장 큰 값을 가지는 보석이 가장 위로 오도록 함
        while (idx < N && bag[i] >= v[idx].first)
        {
            pq.push(v[idx].second);
            ++idx;
        }
        
        // 가치가 가장 높은 보석을 가방에 넣는다
        if (!pq.empty())
        {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";
    return 0;
}