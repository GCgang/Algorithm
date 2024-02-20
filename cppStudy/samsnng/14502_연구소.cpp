/*
벽 3개 세우기
바이러스 퍼트리기
안전영역 개수 세기 및 업데이트
0=빈칸 1=벽 2=바이러스
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N, M, ret;
int board[9][9];
int visited[9][9];
int temp[9][9];
queue<pair<int, int> > virus;
vector<pair<int, int> > blank;

int bfs()
{
    while (!virus.empty())
    {
        int y = virus.front().first;
        int x = virus.front().second;
        visited[y][x] = 1;
        virus.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (visited[ny][nx] || temp[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            temp[ny][nx] = 2;
            virus.push(make_pair(ny,nx));
        }
    }
    int blankCnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (temp[i][j] == 0)
                blankCnt++;
        }
    }
    return blankCnt;
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                blank.push_back(make_pair(i,j)); // 빈칸 좌표 벡터
            else if (board[i][j] == 2)
                virus.push(make_pair(i,j)); // 바이러스 좌표 벡터
        }
    }

    vector<int> combi(blank.size(), 1);
    fill(combi.begin(), combi.begin() + blank.size() - 3, 0); // 빈공간 중 벽이 들어갈 수 있는 조합
    do
    {
        // 3개의 벽을 세우는 조합마다 바이러스를 퍼트리기 때문에
        // 한 조합에서 안전영역의 개수를 구한 이후에는 초기화 해야함
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                temp[i][j] = board[i][j];
                if (temp[i][j] == 2)
                    virus.push(make_pair(i,j)); // 큐에서 다 뺐기 때문에 다시 푸쉬
            }
        }
        // 방문 배열을 visited에서 사용했으므로 초기화해줌
        for (int i = 0; i < 9; ++i)
            fill(visited[i], visited[i] + 9, 0);
        // 빈칸에 3개의 벽 세우기
        for (int i = 0; i < combi.size(); ++i)
        {
            if (combi[i] == 1)
                temp[blank[i].first][blank[i].second] = 1;
        }
        ret = max(ret, bfs());
    }while(next_permutation(combi.begin(), combi.end()));

    cout << ret;
    return 0;
}
