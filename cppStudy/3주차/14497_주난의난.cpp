// https://www.acmicpc.net/problem/14497
/*
문제:
주난이는 크게 화가 났다.
책상 서랍 안에 몰래 먹으려고 숨겨둔 초코바가 사라졌기 때문이다
주난이는 미쳐 날뛰기 시작했다. 사실, 진짜로 뛰기 시작했다
주난이는 점프의 파동으로 주변의 모든 친구들을 쓰러트리고 도둑맞은 초코바를 찾으려고 한다
주난이는 NxM크기의 학교 교실 어딘가에서 뛰기 시작했다
주난이의 파동은 상하좌우 4방향으로 친구들을 쓰러트릴 때 까지 계속해서 퍼져나간다
다르게 표현해서, 한 번의 점프는 한 겹의 친구들을 쓰러뜨린다

1 # 1 0 1 1 1
1 1 0 1 0 0 1
0 0 1 * 1 1 1
1 1 0 1 1 1 1
0 0 1 1 0 0 1

주난이를 뜻하는 *은 (3,4)에 있고, 초코바를 가진 학생 #는 (1,2)에 있다.
0은 장애물이 없는 빈 공간임을 뜻하고,
1은 친구들이 서있음을 의미한다.
다음은 주난이의 점프에 따른 생존 학생들의 변화이다

1 # 1 0 1 1 1
1 1 0 0 0 0 1
0 0 0 * 0 1 1
1 1 0 0 1 1 1
0 0 1 1 0 0 1

1 # 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 * 0 0 1
0 0 0 0 0 1 1
0 0 0 0 0 0 1

0 X 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 * 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0

위의 예시에서 주난이는 3번의 점프 만에 초코바를 훔쳐간 범인을 찾아낼 수 있다
주난이를 빨리 멈춰야 교실의 안녕을 도모할 수 있다
주난이에게 최소 점프 횟수를 알려줘서 교실을 지키자

입력:
첫째 줄에 주난이가 위치한 교실의 크기 N, M이 주어진다 (1 <= N, M <= 300)
둘째 줄에 주난이의 위치 x1, y1과 범인의 위치 x2, y2가 주어진다 (1 <= x1, x2 <= N, 1 <= y1, y2 <= M)
이후, NxM 크기의 교실 정보가 주어진다.
0은 빈 공간, 1은 친구, *는 주난, #는 범인을 뜻한다.

출력:
주난이가 범인을 잡기 위해 최소 몇 번의 점프를 해야 하는지 출력한다

ex:
입력
5 7
3 4 1 2
1#10111
1101001
001*111
1101111
0011001

출력
3
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dy[4] = {-1, 0, 1, 0};
	int dx[4] = {0, 1, 0, -1};
	int N, M, junanY, junanX, crimianlY, criminalX, jump = 0;
	vector<vector<char> > map;
	vector<vector<int> > visited;

	cin >> N >> M;
	cin >> junanY >> junanX >> crimianlY >> criminalX;
	--junanY, --junanX, --crimianlY, --criminalX;

	map.resize(N, vector<char>(M));
	visited.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
		}
	}

    visited[junanY][junanX] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(junanY, junanX));

	// 주난이는 범인을 찾을 때까지 뛸 것이다
	while (1)
	{		
        jump++;
        queue<pair<int, int> > temp;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
		
			// 범인을 찾은 경우
			if (map[y][x] == '#')
			{
				cout << jump << "\n";
				return 0;
			}
			// 4방향으로 파동은 퍼져나감
			for (int i = 0; i < 4; ++i)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
			
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (visited[ny][nx])
					continue;

				visited[ny][nx] = visited[y][x] + 1;
				if (map[ny][nx] == '1')
                {
					map[ny][nx] = '0';
                    temp.push(make_pair(ny, nx));
                }
				else
					q.push(make_pair(ny,nx));
			}
		}
        q = temp;
	}
	return 0;
}
