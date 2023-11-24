// https://www.acmicpc.net/problem/1546
#include <iostream>
#include <vector>
using namespace std;

/*
문제:
자기 점수 중 최대값을 고르고, 그 최댓값을 M이라 할 때
모든 점수를 점수 / M * 100으로 고첬다.
예를 들어, 최고점이 70점, 수학 점수가 50점이라면 수학 점수는 50 / 70 * 100 이므로 71.43점이다.
이 방법으로 성적을 계산했을 때, 새로운 평균을 구하는 프로그램을 작성하시오.

입력:
1번째 줄에 시험을 본 과목의 개수 N이 주어진다.(N <= 1000)
2번째 줄에 현재 성적이 주어진다(0 <= 성적 <= 100) -> 이중 적어도 1개의 값은 0보다 크다

출력:
1번째 줄에 새로운 평균을 출력한다.
실제 정답과 출력값의 절대 오차 또는 상대 오차가 10^-2 이하이면 정답이다.

변환 점수의 평균을 구하는 식(점수가 A, B, C인 경우):
(A / M * 100 + B / M * 100 + C / M * 100) / 3 = (A + B + C) * 100 / M / 3
*/

int main()
{
    int N = 0;
    int testScores[1000];
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> testScores[i];
    }

    int M = 0;
    int totalScore = 0;

    for (int i = 0; i < N; i++)
    {
        if (testScores[i] > M)
        {
            M = testScores[i];
        }
        totalScore += testScores[i];
    }

    double average = (totalScore * 100.0 / M) / N;
    cout << average << endl;
    return 0;
}