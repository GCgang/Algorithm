// https://www.acmicpc.net/problem/1260
/*
문제:
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오
단, 방문할 수 있는 노드가 여러 개일 경우에는 노드 번호가 작은 것을 먼저 방문하고 더 이상 방문할 수 있는 노드가 없을 때 종료한다
노드 번호는 1에서 N까지다

입력:
1번째 줄에 노드의 개수 N(1 <= N <= 1000), 에지의 개수 M(1 <= M <= 10,000)
탐색을 시작할 노드의 번호 V가 주어진다
그다음 M개의 줄에는 에지가 연결하는 두 노드의 번호가 주어진다
어떤 두 노드 사이에 여러 개의 에지가 있을 수 있다.
입력으로 주어지는 에지는 양방향이다

출력:
1번째 줄에 DFS를 수행한 결과,
그다음 주에 BFS를 수행한 결과를 출력한다
V부터 방문한 점을 순서대로 출력하면 된다

ex:
입력                                  출력
4 5 1 (노드개수, 에지개수, 시작점)         1 2 4 3
1 2                                  1 2 3 4
1 3
1 4
2 4
3 4
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector <int> > Alist;
static vector<bool> visited;
static bool arrive;
void DFS(int node);
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, Start;

    cin >> N >> M >> Start;
    Alist.resize(N + 1);
    arrive = false;

    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;
        Alist[s].push_back(e);
        Alist[e].push_back(s);
    }
    // 방문할 수 있는 노드가 여러 개일 때는 번호가 작은 것을 먼저 방문하기 위해 정렬
    for (int i = 1; i <= N; ++i)
        sort(Alist[i].begin(), Alist[i].end());
    
    visited = vector<bool>(N + 1, false);
    DFS(Start);
    cout << "\n";
    fill(visited.begin(), visited.end(), false);
    BFS(Start);
    cout << "\n";

    return 0;
}

void DFS(int node)
{
    cout << node << " ";
    visited[node] = true;

    for (int i : Alist[node])
    {
        if(visited[i] == false)
            DFS(i);
    }
}

void BFS(int node)
{
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while (myqueue.empty() == false)
    {
        int now_node = myqueue.front();
        myqueue.pop();
        cout << now_node << " ";
        for (int i : Alist[now_node])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}