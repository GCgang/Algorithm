// https://www.acmicpc.net/problem/11660
/*

문제:
N x N개의 수가 N x N 크기의 표에 채워져 있다.
표 안의 수 중 (X1, Y1)에서 (X2, Y2)까지의 합을 구하려 한다.
X는 행, Y는 열을 의미한다. 예를 들어 N = 4이고, 표가 다음과 같이 채워져 있을 대를 살펴보자

표:
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7

(2,2)에서 (3,4)까지의 합을 구하면 3 + 4 + 5 + 4 + 5 + 6 = 27이고,
(4,4)에서 (4,4)까지의 합을 구하면 7이다.
표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때 이를 처리하는 프로그램을 작성하기오.

입력:
1번째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다 (1 <= N <= 1024) (1 <= M <= 100,000)
2번째 줄부터 N개의 줄에는 표에 채워져  있는 수가 1행부터 차례대로 주어진다.
다음 M개의 줄에는 4개의 정수 X1, Y1, X2, Y2가 주어지며, (X1, Y1)에서 (X2, Y2)의 합을 구해 출력해야 한다.
표에 채워져 있는 수는 1,000보다 작거나 같은 자연수다 (X1 <= X2) (Y1 <= Y2)

출력:
총 M줄에 걸쳐 (X1, Y1)에서 (X2, Y2)까지 합을 구해 출력한다.

ex:
입력:                                              출력:
4 3         2차원 배열의 크기, 구간 합 질의의 개수          27
1 2 3 4     원본 배열 1번째 줄                          6
2 3 4 5     원본 배열 2번째 줄                          64
3 4 5 6     원본 배열 3번째 줄                  
4 5 6 7     원본 배열 4번째 줄 
2 2 3 4     구간 합(X1, Y1), (X2, Y2) 1번째 질의
3 4 3 4     구간 합(X1, Y1), (X2, Y2) 2번째 질의
1 1 4 4     구간 합(X1, Y1), (X2, Y2) 3번째 질의

2차원 구간 합 배열 D[X][Y]정의:
D[X][Y] = 원본 배열의 (0, 0)부터 (X, Y)까지의 사각형 영역 안에 있는 수의 합

D[i][j]의 값을 채우는 구간 합 공식
D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + A[i][j]

질의 X1, Y1, X2, Y2에 대한 답을 구간 합으로 구하는 방법:
D[X2][Y2] - D[X1-1][Y2] - D[X2][Y1-1] + D[X1-1][Y1-1]
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, quizCnt = 0;
    cin >> N >> quizCnt;

    vector<vector<int> > numArray(N + 1, vector<int>(N + 1, 0));
    vector<vector<int> > sumArray(N + 1, vector<int>(N + 1, 0));

    // 원본 배열 저장
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> numArray[i][j];

            // 구간 합 배열 저장
            sumArray[i][j] = \
                            sumArray[i][j-1] \
                            + sumArray[i-1][j] \
                            - sumArray[i-1][j-1] \
                            + numArray[i][j];
        }
    }

    // 질의 계산 및 출력
    for (int i = 0; i < quizCnt; i++)
    {
        int X1, Y1, X2, Y2 = 0;
        int prefixSum = 0;

        cin >> X1 >> Y1 >> X2 >> Y2;
        prefixSum = \
                    sumArray[X2][Y2] \
                    - sumArray[X1-1][Y2] \
                    - sumArray[X2][Y1-1] \
                    + sumArray[X1-1][Y1-1];

        cout << prefixSum << "\n";
    }
    return 0;
}