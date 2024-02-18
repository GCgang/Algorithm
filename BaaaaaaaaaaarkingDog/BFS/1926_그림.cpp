// https://www.acmicpc.net/problem/1926
/*
문제:
어떤 큰 도화지에 그림이 그려져 있을 떄, 그 그림의 개수와,
그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라.
단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자
가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다.
그림의 넓이란 그림에 포함된 1의 개수이다.

입력:
첫째 줄에 도화지의 세로 크기 n(1 <= n <= 500)과 가로 크기 m(1 <= m <= 500)이 차례로 주어진다.
두 번쨰 줄부터 n+1 줄 까지 그림의 정보가 주어진다
(단 그림의 정보는 0과 1이 공백을 두고 주어지며, 0은 색칠이 안된 부분, 1은 색칠이 된 부분을 의미한다)

출력:
첫째 줄에는 그림의 개수,
둘쨰 줄에는 그 중 가장 넓은 그림의 넓이를 출력하여라
단, 그림이 하나도 없는 경우에는 가장 넓은 그림의 넓이는 0이다

ex:
입력
6 5
1 1 0 1 1
0 1 1 0 0
0 0 0 0 0
1 0 1 1 1
0 0 1 1 1
0 0 1 1 1

출력
4
9
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, cnt, maxWidth = 0;
int paper[501][501];
int visited[501][501];

int BFS(int y, int x)
{
    int ret = 1;
    queue<pair<int, int> > q;
    visited[y][x] = 1;
    q.push(make_pair(y, x));

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (!paper[ny][nx] || visited[ny][nx])
                continue;
            visited[ny][nx] = 1;
            ret++;
            q.push(make_pair(ny, nx));
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> paper[i][j];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (paper[i][j] && !visited[i][j])
            {
                cnt++;
                maxWidth = max(maxWidth, BFS(i, j));
            }
        }
    }

    cout << cnt << "\n";
    cout << maxWidth << "\n";
    return 0;
}