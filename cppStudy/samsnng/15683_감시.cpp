// https://www.acmicpc.net/problem/15683

/*
cctv의 개수만큼 확인하며 4각지대를 확인한다
0 빈칸
6 벽
1 ~ 5 cctv
감시 # = 7

사무실 크기 N x M (1 <= N, M <= 8)
cctv 개수 최대 8
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N, M, dir, ret = 2147483647;
int office[9][9];
vector<pair<int, int> > cctvs;

/*
cctv마다 현재 감시 가능한 곳을 맵에 기록한다
가지고 있는 cctv다 확인하면 사각지대 개수를 구한다
가지고 있는 cctv의 방향을 회전시켜 확인하며 사각지대의 최소 개수를 구한다
*/ 

void watch(int y, int x, int dir)
{
    dir %= 4;
    while(true)
    {
        y += dy[dir];
        x += dx[dir];

        if (y < 0 || y >= N || x < 0 || x >= M)  // 범위 확인
            return;
        if (office[y][x] == 6) // 벽 확인
            return;
        if (office[y][x] == 7) // 이미 감시된 구역 확인
            continue;
        if (office[y][x] >= 1 && office[y][x] <= 5) 
            continue;
        office[y][x] = 7; // 감시할 수 있는 경우
    }
}
void dfs(int k)
{
    if (k == cctvs.size())
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (office[i][j] == 0) // 사각지대인 경우
                    cnt++;
            }
        }
        ret = min(cnt, ret); // cctv를 방향마다 회전하며 돌린 것 중 사각지대가 최소인 수를 구함
        return ;
    }

    int y = cctvs[k].first;
    int x = cctvs[k].second;
    int cctvType = office[y][x]; // cctv 종류를 구함
    int temp[9][9];

    for (int dir = 0; dir < 4; ++dir)
    {
        copy(&office[0][0], &office[0][0] + 9*9, &temp[0][0]); // temp에 원본을 복사해둠

        if (cctvType == 1) { // cctv 1
            watch(y, x, dir);
        }
        else if (cctvType == 2) { // cctv 2
            watch(y, x, dir);
            watch(y, x, dir+2);
        }
        
        else if (cctvType == 3) { // cctv 3
            watch(y, x, dir);
            watch(y, x, dir+1);
        }
        else if (cctvType == 4) {  // cctv 4
            watch(y, x, dir);
            watch(y, x, dir+1);
            watch(y, x, dir+2);
        }
        else if (cctvType == 5) { // cctv 5
            watch(y, x, dir);
            watch(y, x, dir+1);
            watch(y, x, dir+2);
            watch(y, x, dir+3);
        }
        dfs(k + 1);
        copy(&temp[0][0], &temp[0][0] + 9*9, &office[0][0]); // 한 조합의 cctv를 보았으니 office를 다시 초기화함
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5)
                cctvs.push_back(make_pair(i,j)); // cctv인 경우 벡터에 좌표값 추가
        }
    }
    dfs(0);

    cout << ret << "\n";
    return 0;
}