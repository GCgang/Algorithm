// https://www.acmicpc.net/problem/1068
/*
문제:
트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.
트리가 주어졌을 때, 노드 하나를 지울 것이다.
그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오.
노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.
입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력하라

입력:
첫째 줄에 트리의 노드의 개수 N이 주어진다.
N은 50보다 작거나 같은 자연수이다.
둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다.
만약 부모가 없다면 (루트)-1이 주어진다.
셋째 줄에는 지울 노드의 번호가 주어진다.

출력:
첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때,
리프 노드의 개수를 출력한다

ex:
입력               출력
5                  2
-1 0 0 1 1
2
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > tree;
vector<int> visited;
int leafNode;
int deleteNode;

int DFS(int here)
{
    visited[here] = 1;

    int leaf = 0;
    int child = 0;
    for (int i = 0; i < tree[here].size(); ++i)
    {
        int there = tree[here][i];

        if (visited[there] || there == deleteNode) // 이미 방문 했거나, 삭제 할 노드이면 탐색 중지
            continue;
        leaf += DFS(there);
        child++;
    }
    if (child == 0) // 자식 노드가 없다면 리프 노드는 자기 자신 이므로 1 리턴
        return 1;
    return leaf;
}

int main()
{
    int N, root;

    cin >> N;
    tree.resize(N);
    visited.resize(N);

    for (int i = 0; i < N; ++i)
    {
        int node;
        cin >> node;
        if (node == -1)
            root = i;
        else
        {
            tree[node].push_back(i);
            tree[i].push_back(node);
        }
    }
    cin >> deleteNode;

    if (root == deleteNode) // 루프 노드가 삭제 노드인 경우는 DFS를 root로 시작하기 때문에 못 찾으므로 0 출력 후 리턴
    {
        cout << 0 << "\n";
        return 0;
    }

    leafNode = DFS(root); // 리프노드 개수 구하기 DFS

    cout << leafNode << "\n";
    return 0;
}