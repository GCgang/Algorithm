// https://www.acmicpc.net/problem/2178
/*
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다.
칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력:
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.
다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력:
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다
항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

ex:
입력								출력
4 6			  					  15
101111
101010
101011
111011

2 25				           	  38
1011101110111011101110111
1110111011101110111011101
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dy[4] = {-1, 0, 1, 0}; // 상 우 하 좌
const int dx[4] = {0, 1, 0, -1}; // 상 우 하 좌

int main()
{
	int N, M;

	cin >> N >> M;

	vector<vector<int> > map(N+1, vector<int>(M+1, 0));
	vector<vector<int> > visited(N+1, vector<int>(M+1, 0));

	for (int i = 1; i <= N; ++i)
	{
		string row;
		cin >> row;
		for (int j = 1; j <= M; ++j)
		{
			map[i][j] = row[j-1] - '0'; // 문자열 정수로 변환
		}
	}

	queue<pair<int, int> > q;
	visited[1][1] = 1;
	q.push(make_pair(1, 1));

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
	
		// 4방향 탐색
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 맵 범위, 벽, 방문 확인
			if (ny < 1 || ny > N || nx < 1 || nx > M)
				continue;
			if (visited[ny][nx])
				continue;
			if (map[ny][nx] == 0)
				continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
	cout << visited[N][M] << "\n";
	// 디버깅 용
	// for (int i = 1; i <= N; ++i)
	// {
	// 	for (int j = 1; j <= M; ++j)
	// 	{
	// 		cout << visited[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	return 0;
}