// https://www.acmicpc.net/problem/1189
/*
문제:
한수는 캠프를 마치고 집에 돌아가려 한다. 한수는 현재 왼쪽 아래점에 있고 집은 오른쪽 위에 있다
그리고 한수는 집에 돌아가는 방법이 다양하다
단, 한수는 똑똑하여 한번 지나친 곳을 다시 방문하지는 않는다

      cdef  ...f  ..ef  ..gh  cdeh  cdej  ...f 
      bT..  .T.e  .Td.  .Tfe  bTfg  bTfi  .Tde 
      a...  abcd  abc.  abcd  a...  a.gh  abc. 
거리 :  6     6     6     8     8    10    6

위 예제는 한수가 집에 돌아갈 수 있는 모든 경우를 나타낸 것이다.
T로 표시된 부분은 가지 못하는 부분이다
문제는 R x C맵에 못가는 부분이 주어지고 거리 K가 주어지면,
한수가 집까지 도착하는 경우 중 거리가 K인 가짓수를 구하려는 것이다.

입력:
첫 줄에 정수 R(1 <= R, 5), C(1 <= C <= 5), K(1 <= K <= RxC)가 공백으로 구분되어 주어진다.
두 번째부터 R+1번째 줄까지는 RxC 맵의 정보를 나타내는 '.'과 'T'로 구성된 길이가 C인 문자열이 주어진다.

출력:
첫 줄에 거리가 K인 가짓수를 출력한다

ex:
입력
3 4 6
....
.T..
....

출력
4
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int R, C, K, ret;
string input;
char map[26][26];
int visited[26][26];

int DFS(int y, int x)
{
      // 집이고, 경우의 수가 같은 경우 1 리턴
      if (y == 0 && x == C - 1)
      {
            if (K == visited[y][x])
                  return 1;
            else
                  return 0;
      }
      int ret = 0;
      for (int i = 0; i < 4; ++i)
      {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 범위 및 이동 불가능한 곳 확인
            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                  continue;
            if (visited[ny][nx] || map[ny][nx] == 'T')
                  continue;
            
            // 방문 횟수 증가 및 
            visited[ny][nx] = visited[y][x] + 1;
            ret += DFS(ny, nx);
            visited[ny][nx] = 0;
      }
      return ret;
}

int main()
{
      cin >> R >> C >> K;

      for(int i = 0; i < R; ++i)
      {
            cin >> input;
            for (int j = 0; j < C; ++j)
            {
                  map[i][j] = input[j];
            }
      }

      int hansuY = R - 1;
      int hansuX = 0;
      visited[hansuY][hansuX] = 1; // 한수의 위치부터 시작
      cout << DFS(hansuY, hansuX) << "\n";
      return 0;
}