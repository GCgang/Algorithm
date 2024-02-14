// https://www.acmicpc.net/problem/18352

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, X;
vector<int> adj[300004];
vector<int> visited(300004, -1); // 각 도시까지의 최단 거리 -1은 방문하지 않음을 의미
queue<int> q;
int main()
{
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    visited[X] = 0; // 출발 도시까지의 거리는 0
    q.push(X);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        // 인접한 노드 탐색(현재 도시에서 이동할 수 있는 모든 도시 탐색)
        for (int i = 0; i < adj[now].size(); ++i) 
        {
            int next = adj[now][i];

            // 아직 방문하지 않은 도시라면 거리 정보에 갱신 및 큐에 추가
            if (visited[next] == -1)
            {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }

    bool check = false;
    for (int i = 1; i <= N; ++i)
    {
        if (visited[i] == K)
        {
            cout << i << "\n";
            check = true; // 한번이라도 출력하면 true
        }
    }

    if(!check)
        cout << -1 << "\n";

    return 0;
}