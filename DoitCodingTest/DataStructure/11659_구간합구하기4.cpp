//https://www.acmicpc.net/problem/11659
/*
문제:
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력:
1번째 줄에 수의 개수 N(1 <= N <= 100,000), 합을 구해야 하는 횟수 M(1 <= M <= 100,000)
2번째 줄에 N개의 수가 주어진다. 각 수는 1,000보다 작거나 같은 자연수이다.
3번째 줄부터는 M개의 줄에 합을 구해야 하는 구간 i와 j가 주어진다.

출력:
총 M개의 줄에 입력으로 주어진 i번째 수에서 j번째 수까지의 합을 출력한다.

ex:
입력                                    출력:
5 3 // 줄의 개수, 합을 구해야 하는 횟수         12
5 4 3 2 1 // 구간 합을 구할 대상 배열          9
1 3                                      1
2 4
5 5
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 시간 단축을 위한 코드 추가
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCnt = 0;
    int quizCnt = 0;

    cin >> numCnt >> quizCnt;
    vector<int> numbers(numCnt + 1, 0);
    vector<int> sumArray(numCnt + 1, 0);

    for (int i = 1; i <= numCnt; i++)
    {
        cin >> numbers[i];
        sumArray[i] = (sumArray[i - 1] + numbers[i]); // 합 배열 구하기
    }

    for (int i = 1; i <= quizCnt; i++)
    {
        int start, end, prefixSum = 0;
        cin >> start >> end;

        prefixSum = sumArray[end] - sumArray[start - 1]; // 구간 합 구하기
        cout << prefixSum << "\n";
    }

    return 0;
}