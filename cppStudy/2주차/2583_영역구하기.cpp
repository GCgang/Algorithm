// https://www.acmicpc.net/problem/2583
/*
문제:
눈금의 간격이 1인 MxN(M,N<=100)크기의 모눈종이가 있다.이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 
이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
예를들어 M=5, N=7인 모눈종이 위에 직사각형 3개를 그렸다면, 그 나머지 영역은 3개의 분리된 영역으로 나누어지게 된다 (링크 그림 참고)
M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지,
그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오

입력:
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다.
둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의
왼쪽 아래 꼭지점의 x, y 좌표값 과 오른쪽 위 꼭짓점의 x, y 좌표값이 빈칸을 사이에 두고 차례로 주어진다.
모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위의 꼭짓점의 좌표는 (N,M)이다.
입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력:
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다.
둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다

ex:
입력            출력
5 7 3           3
0 2 4 4        1 7 13
1 1 2 5
4 0 6 2

connected component 문제

x2, y2에 -1을 한 맵 좌표
(0,4) (1,4) (2,4) (3,4) (4,4) (5,4) (6,4)
(0,3) (1,3) (2,3) (3,3) (4,3) (5,3) (6,3)
(0,2) (1,2) (2,2) (3,2) (4,2) (5,2) (6,2)
(0,1) (1,1) (2,1) (3,1) (4,1) (5,1) (6,1)
(0,0) (1,0) (2,0) (3,0) (4,0) (5,0) (6,0)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int M, N, K;
int a[101][101];
bool visited[101][101];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

// 분리된 영역을 돌아다니면서 영역의 개수를 세어주는 DFS
int DFS(int y, int x)
{
    visited[y][x] = true;
    int cnt = 1;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N)
            continue;
        if (a[ny][nx] || visited[ny][nx])
            continue;
        cnt += DFS(ny, nx);
    }

    return cnt;
}
int main()
{
    cin >> M >> N >> K;
    
    // 주어진 좌표 색칠
    for (int i = 0; i < K; ++i)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; ++x)
        {
            for (int y = y1; y < y2; ++y)
            {
                a[y][x] = 1;
            }
        }
    }

    // dfs 로 구해진 영역 개수를 벡터에 저장
    vector<int> cntArray;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!a[i][j] && !visited[i][j])
                cntArray.push_back(DFS(i, j));
        }
    }

    // 영역 개수를 오름차순으로 정렬 후 출력
    sort(cntArray.begin(), cntArray.end());

    cout << cntArray.size() << "\n";
    for (int i = 0; i < cntArray.size(); ++i)
    {
        cout << cntArray[i] << " ";
    }
    return 0;
}