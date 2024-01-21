// https://www.acmicpc.net/problem/1012
/*
문제:
지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 
어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들 역시 해충으로부터 보호받을 수 있다.
한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있는 것이다.
한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어 놓았다. 
배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇 마리의 지렁이가 필요한지 알 수 있다.
예를 들어 배추밭이 아래와 같이 구성되어 있으면 최소 5마리의 배추흰지렁이가 필요하다
0은 배추가 심어져 있지 않은 땅이고, 1은 배추가 심어져 있는 땅을 나타낸다.
1	1	0	0	0	0	0	0	0	0
0	1	0	0	0	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	0	0	1	0	0	0	0	0
0	0	1	1	0	0	0	1	1	1
0	0	0	0	1	0	0	1	1	1

입력:
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다.
그 다음 줄부터 각각의 테스트 케이스에 대해
첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)
세로길이 N(1 ≤ N ≤ 50)
배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다.
그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 
두 배추의 위치가 같은 경우는 없다.

출력:
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.

ex:
입력				출력
2				   5
10 8 17            1
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5

connected component 문제
*/

#include <iostream>
#include <vector>
using namespace std;

int M, N;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void DFS(vector<vector<int> > &adj, vector<vector<bool> > &visited, int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if (adj[ny][nx] == 1 && !visited[ny][nx])
			DFS(adj, visited, ny, nx);
	}
}

int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int K;

		cin >> M >> N >> K;

		vector<vector<int> > adj(N, vector<int>(M, 0));
		vector<vector<bool> > visited(N, vector<bool>(M, false));
		for (int i = 0; i < K; ++i)
		{
			int x, y;
			cin >> x >> y;
			adj[y][x] = 1;
		}
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (adj[i][j] && !visited[i][j])
				{
					res++;
					DFS(adj, visited, i, j);
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}
