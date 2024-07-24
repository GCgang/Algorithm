// https://www.acmicpc.net/problem/11724
/*
문제:
방향 없는 그래프가 주어졌을 때, 연결 요소(Connected Component)의 개수를 구하는 프로그램을 작성하시오

입력:
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다
1 <= N <= 1,000
0 <= M <= Nx(N-1)/2
둘째 줄 부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다
1 <= u
v <= N
u != v
같은 간선은 한 번만 주어진다

출력:
첫째 줄에 연결 요소의 개수를 출력한다

ex:
입력            출력
6 5             2
1 2
2 5
5 1
3 4
4 6
*/
#include <iostream>
#include <vector>
using namespace std;

static vector<vector <int> > Alist;
static vector<bool> visited;
void DFS(int v);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;

    cin >> N >> M;

    Alist.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        Alist[u].push_back(v);
        Alist[v].push_back(u);
    }

    int connected = 0;

    for (int i = 1; i < N + 1; ++i)
    {
        if (visited[i] == false)
        {
            connected++;
            DFS(i);
        }
    }
    cout << connected << "\n";
    return 0;
}

void DFS(int v)
{
    if (visited[v] == true)
        return ;

    visited[v] = true;

    for (int i = 0; i < Alist[v].size(); ++i)
    {
        int j = Alist[v][i];
        if (visited[j] == false)
        {
            DFS(j);
        }
    }
}