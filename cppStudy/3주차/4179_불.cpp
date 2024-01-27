// https://www.acmicpc.net/problem/4179
/*
문제:
지훈이는 미로에서 일을 한디. 지훈이를 미로에서 탈출하도록 도와주자
미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부,
그리고 얼마나 빨리 탈출할 수 있는지를 결정 해야한다.
지훈이와 불은 매 분마다 한 칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)이동한다.
불은 각 지점에서 네 방향으로 확산된다
지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다
지훈이와 불은 벽이 있는 공간은 통과하지 못한다

입력:
입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다.
단, 1 <= R, C <= 1000이다.
R은 미로 행의 개수, C는 열의 개수이다.
다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
각각의 문자들은 다음을 뜻한다.
	#: 벽
	.: 지나갈 수 있는 공간
	J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
	F: 불이 난 공간
J는 입력에서 하나만 주어진다

출력:
지훈이가 불이 도달하기 전에 미로를 탈출할 수 없는 경우 IMPOSSIBLE을 출력한다.
지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다

ex:
입력
4 4
####
#JF#
#..#
#..#

출력
3
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int dy[4] = {-1, 0, 1, 0};
	int dx[4] = {0, 1, 0, -1};
	int N, M, personY, personX;
	queue<pair<int, int> > q;
	cin >> N >> M;

	vector<vector<char> > map(N, vector<char>(M, 0));
	vector<vector<int> > fire(N, vector<int>(M, 987654321));
	vector<vector<int> > person(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'F')
			{
				fire[i][j] = 1;
				q.push(make_pair(i, j));
			}
			else if (map[i][j] == 'J')
			{
				personY = i;
				personX = j;
			}
		}
	}

	int y, x;
	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (map[ny][nx] == '#' || fire[ny][nx] != 987654321) // 벽이거나 불이 한번도 도달하지 않았으면 continue
				continue;
			fire[ny][nx] = fire[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}

	person[personY][personX] = 1;
	q.push(make_pair(personY, personX));
	int ret = 0;
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (x == M -1 || y == N - 1 || x == 0 || y == 0)
		{
			ret = person[y][x]; // 지후인가 가장자리에 도착한 경우
			break;
		}
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (person[ny][nx] || map[ny][nx] == '#')
				continue;
			if (fire[ny][nx] <= person[y][x] + 1)
				continue;
			person[ny][nx] = person[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
	if (ret != 0)
		cout << ret << "\n";
	else
		cout << "IMPOSSIBLE \n";
	return 0;
}