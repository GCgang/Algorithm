// https://www.acmicpc.net/problem/2178
/*
문제:
N×M크기의 배열로 표현되는 미로가 있다.
1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1

미로에서 1은 이동할 수 있는 칸을 나타내고,
0은 이동할 수 없는 칸을 나타낸다.
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때
지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다.
칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력:
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.
다음 N개의 줄에는 M개의 정수로 미로가 주어진다.
각각의 수들은 붙어서 입력으로 주어진다.

출력:
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다.
항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

ex:
입력
4 6
101111
101010
101011
111011

출력
15
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M, ret;
string s;
int miro[101][101];
int visited[101][101];
queue<pair<int, int> > q;
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> s;
        for (int j = 0; j < M; ++j)
        {
            miro[i][j] = s[j] - '0';
        }
    }

    q.push(make_pair(0,0));
    visited[0][0] = 1;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (!miro[ny][nx] || visited[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny,nx));
        }
    }

    cout << visited[N-1][M-1] << "\n";
    return 0;
}