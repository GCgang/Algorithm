// https://www.acmicpc.net/problem/11050
/*
문제:
자연수 N과 정수 K가 주어졌을 때 이항 계수 N/K를 구하는 프로그램을 작성하시오

입력:
첫째 줄에 N과 K가 주어진다 (1 <= N <= 10, 0 <= K <= N)

출력:
N/K를 출력한다

ex:
입력
5 2

출력
10
*/


#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    int N, K;
    int D[11][11];

    memset(D, 0, sizeof(D));
    std::cin >> N >> K;
    
    
    for (int i = 0; i <= N; ++i)
    {
        D[i][1] = i; // i개에서 1개 선택 경우의 수는 i개
        D[i][0] = 1; // i개에서 하나도 선택 안 하는 경우의 수는 1개
        D[i][i] = 1; // i개에서 모두 선택하는 경우의 수는 1개
    }

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            D[i][j] = D[i - 1][j] + D[i -1][j - 1]; // 조합 기본 점화식
        }
    }
    cout << D[N][K] << "\n";
}
