// https://www.acmicpc.net/problem/1325
/*
문제:
어떤 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데,
A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.

입력:
첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다.
둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다.
컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.

출력:
첫째 줄에, 한번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력한다.

ex: 
입력            출력
5 4            1 2
3 1
3 2
4 3
5 3
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[10001];
vector<bool> visited(10001, 0);
vector<int> computer(10001, 0);
int N, M;

int DFS(int here)
{
    visited[here] = true;
    int cnt = 1;

    for (int next : adj[here])
    {
        if (visited[next])
            continue;
        cnt += DFS(next);
    }
    // 위와 같음
    // for (int i = 0; i < adj[here].size(); ++i)
    // {
    //     int next = adj[here][i];
    //     if (!visited[next])
    //         continue;
    //     cnt += DFS(next);
    // }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; ++i)
    {
        int A, B;
    
        cin >> A >> B;
        adj[B].push_back(A); // A는 B를 신뢰하기 때문에 B를 신뢰하는 컴퓨터를 모두 해킹하기 위해 B를 신뢰하는 컴퓨터를 구함
    }

    int maxCnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        fill(visited.begin(), visited.end(), false);
        computer[i] = DFS(i);
        maxCnt = max(computer[i], maxCnt);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (computer[i] == maxCnt)
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}