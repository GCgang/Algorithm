// https://www.acmicpc.net/problem/13023
/*
문제:
총 N명의 사람들은 0번부터 N-1번으로 번호가 매겨져 있고 일부 사람들은 친구이다
다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다
- A는 B와 친구다
- B는 C와 친구다
- C는 D와 친구다
- D는 E와 친구다
위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오

입력:
1번 쨰 줄에 사람의 수 N(5 <= N <= 2000)과 친구 관계의 수 M(1 <= 2000)이 주어진다
2번 째 부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다
(0 <= a, b <= N-1, a != b)같은 친구 관계가 두 번 이상 주어지는 경우는 없다

출력:
문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다

ex:
입력        출력
5 4         1
0 1
1 2
2 3
3 

6 5         0
0 1
0 2
0 3
0 4
0 5
*/
#include <iostream>
#include <vector>
using namespace std;

static vector<vector <int> > Alist;
static vector<bool> visited;
static bool arrive;
void DFS(int now, int depth);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;
    arrive = false;
    Alist.resize(N);
    visited = vector<bool>(N, false);

    // 인접 리스트 생성
    for (int i = 0; i < M; ++i)
    {
        int a, b;

        cin >> a >> b;
        Alist[a].push_back(b);
        Alist[b].push_back(a);
    }
    // 노드마다 DFS 실행
    for (int i = 0; i < N; ++i)
    {
        DFS(i, 1);
        if (arrive)
            break ;
    }

    if (arrive == true)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
    
    return 0;
}

void DFS(int now, int depth)
{
    // depth가 5가되면 프로그램 종료
    if (depth == 5 || arrive)
    {
        arrive = true;
        return ;
    }
    visited[now] = true;

    for (int i = 0; i < Alist[now].size(); ++i)
    {
        int next_node = Alist[now][i]; // now 노드에 인접한 노드를 next_node로 지정
        if (visited[next_node] == false)
            DFS(next_node, depth + 1);
    }
    visited[now] = false;
}