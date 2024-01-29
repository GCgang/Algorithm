// https://www.acmicpc.net/problem/16234
/*
문제:
NxN크기의 땅이 있고, 땅은 1x1개의 칸으로 나누어져 있다.
각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다.
인접한 나라 사이에는 국경선이 존재한다. 모든 나라는 1x1 크기이기 때문에, 모든 국경선은 정사각형 형태이다
오늘부터 인구 이동이 시작되는 날이다.
인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.
	1. 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면,
	두 나라가 공유하는 궁경선을 오늘 하루 동안 연다
	2. 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다
	3. 연합을 이루고 있는 각 칸의 인구수는(연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다
	편의상 소수점을 버린다
	4. 연합을 해체하고, 모든 국경선을 닫는다.
각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하시오

입력:
첫째 줄에 N, L, R이 주어진다 (1 <= N <= 50, 1 <= L <= R <= 100)
둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다.
r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 <= A[r][c] <= 100)
인구 이동이 발생하는 일수가 2000번 보다 작거나 같은 입력만 주어진다

출력:
인구 이동이 며칠 동안 발생하는지 첫째 줄에 출력한다

ex:
입력
2 20 50
50 30
20 40

출력
1 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<vector<int> > map;
int visited[51][101];
vector<pair<int, int> > country;
int N, L, R, sum, cnt;

// 연합을 형성할 나라들을 찾고, 연합에 포함시키는 함수
void DFS(int y, int x)
{
    for (int i = 0; i < 4; ++i)
	{
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (visited[ny][nx])
            continue;
        if (abs(map[ny][nx] - map[y][x]) >= L && abs(map[ny][nx] - map[y][x]) <= R)
		{
            visited[ny][nx] = 1;
            country.push_back(make_pair(ny, nx));
            sum += map[ny][nx]; // 연합 총 인구수에 추가
            DFS(ny, nx);
        }
    }
}
int main()
{
	cin >> N >> L >> R;

	map.resize(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
		}
	}

	while(true)
	{
		bool moved = false;
        memset(visited, 0, sizeof(visited));

		// 모든 나라 순회
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (!visited[i][j])
                {
                    visited[i][j] = 1;
                    country.clear();
                    country.push_back(make_pair(i,j));
                    sum = map[i][j];
                    DFS(i,j);
                    if (country.size() == 1)
                        continue;
                    // 연합 생성시 인구 이동 처리
                    for (pair<int, int> p : country)
                    {
                        map[p.first][p.second] = sum / country.size();
                        moved = true;
                    }
                }
			}
		}
		if (!moved)
			break;
		cnt++;
	}
	cout << cnt << "\n";
	return 0;
}