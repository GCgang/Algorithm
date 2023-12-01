// https://www.acmicpc.net/problem/1253
/*
문제:
N개의 수 중에서 어떤 수가 다른 수 두개의 합으로 나타낼 수 있다면 그 수를 "좋다(GOOD)"고 한다
N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라
수의 위치가 다르면 값이 같아도 다른 수이다.

입력:
1번째 줄에 수의 개수 N(1 <= N <= 2,000)
2번째 줄에 N개의 수의 값(Ai)이 주어진다(|Ai| <= 1,000,000,000, Ai는 정수)

출력:
좋은 수의 개수를 1번째 줄에 출력한다.

ex:
입력                    출력
10                      8
1 2 3 4 5 6 7 8 9 

투 포인터 이동 원칙:
A[i] + A[j] > K: j--;
A[i] + A[j] < K: i++;
A[i] + A[j] == K: count++ 프로세스 종료
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCnt;

    cin >> numCnt;

    vector<int> numArray(numCnt, 0);

    for (int i = 0; i < numCnt; i++)
    {
        cin >> numArray[i];
    }

    sort(numArray.begin(), numArray.end());
    int nice = 0;

    for (int k = 0; k < numCnt; k++)
    {
        int find = numArray[k];
        int i = 0;
        int j = numCnt - 1;

        while (i < j)
        {
            if (numArray[i] + numArray[j] == find)
            {
                if (i != k && j != k)
                {
                    nice++;
                    break;
                }
                else if (i == k)
                {
                    i++;
                }
                else if (j == k)
                {
                    j--;
                }
            }
            else if (numArray[i] + numArray[j] < find)
            {
                i++;
            }
            else if (numArray[i] + numArray[j] > find)
            {
                j--;
            }
        }
    }
    cout << nice << "\n";
    return 0;
}
