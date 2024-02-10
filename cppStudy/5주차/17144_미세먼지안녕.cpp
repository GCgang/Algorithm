// https://www.acmicpc.net/problem/17144


#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm> 
using namespace std;

// 공기 청정기 윗부분
int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
// 공기 청정기 아랫부분
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};  

int R, C, T, ret = 0;
int map[54][54], temp[54][54];
vector<pair<int, int> > v1, v2;

// 청정기 순환 경로 계산
vector<pair<int, int> > cleaner(int sy, int sx, int dy[], int dx[])
{
	vector<pair<int, int> > v;

	int cnt = 0;
	int y = sy;
	int x = sx;

	while (true)
	{
		int ny = y + dy[cnt];
		int nx = x + dx[cnt];
		// 시작점이면 종료
		if (ny == sy && nx == sx) 
			break;
		// 범위 벗어날 경우 방향 전환
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
		{
			cnt++;
			continue;
		}
		// 순환 경로에 위치 추가
		v.push_back(make_pair(ny, nx));
		y = ny;
		x = nx;
	}
	return (v);
}

// 미세먼지 확산 처리
void dustGo()
{
	memset(temp, 0,sizeof(temp));
	// fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
	queue<pair<int, int> > q;

	// 미세먼지 위치 큐에 추가
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] != -1 && map[i][j])
			{
				q.push(make_pair(i, j));
			}
		}
	}

	// 미세먼지 확산처리
	while (q.size())
	{
		int y, x;
		y = q.front().first;
		x = q.front().second;
		int spread = map[y][x] / 5; // 확산되는 미세먼지 양
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy1[i];
			int nx = x + dx1[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue;
			if (map[ny][nx] == -1)
				continue;
			temp[ny][nx] += spread; // 임시배열에 확산량 추가
			map[y][x] -= spread; // 기존 위치에서 확산량 감소
		}
	}
	// 확산된 미세먼지 실제 배열에 반영
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			map[i][j] += temp[i][j];
		}
	}
}

// 공기청정기 작동
void cleanerGo(vector<pair<int, int> >& v)
{
	for (int i = v.size() - 1; i > 0; i--)
	{
		map[v[i].first][v[i].second] = map[v[i - 1].first][v[i - 1].second]; 
	}
	map[v[0].first][v[0].second] = 0; // 청정기 바로 뒤는 미세먼지 없음
}

int main()
{
	cin >> R >> C >> T;
	bool top = true;

	// 맵 정보와 공기 청정기 순환 경로 구하기
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				if (top)
				{
					v1 = cleaner(i, j, dy1, dx1);
					top = false;
				}
				else
					v2 = cleaner(i, j, dy2, dx2);
			}

		}
	}

	// T초 동안 확신 및 청정기 돌리기
	while (T--)
	{
		dustGo();
		cleanerGo(v1);
		cleanerGo(v2);
	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (map[i][j] != -1)
				ret += map[i][j];
		}
	}
	cout << ret << "\n";

	return 0;
}