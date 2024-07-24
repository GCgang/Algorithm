// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>
using namespace std;

int computer, N, ret;
int visited[101];
vector<vector<int> > network;

void DFS(int y)
{
    visited[y] = 1;

    for (int i = 0; i < network[y].size(); ++i)
    {
        int next = network[y][i];

        if (visited[next])
            continue;;
        visited[next] = 1;
        ret++;
        DFS(next);
    }
} 
int main()
{
    cin >> computer >> N;

    network.resize(computer + 1);

    for (int i = 0; i < N; ++i)
    {
        int to, from;
        cin >> to >> from;

        network[to].push_back(from);
        network[from].push_back(to);
    }

    DFS(1);

    cout << ret << "\n";
    return 0;
}