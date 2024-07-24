// https://www.acmicpc.net/problem/2018
/*
문제:
어떠한 자연수 N은 몇 개의 연속된 자연수의 합으로 나타낼 수 있다.
당신은 어떤 자연수 N(1 <= N <= 10,000,000)을 몇 개의 연속된 자연수의 합으로 나타내는 가짓수를 알고 싶다.
이 때 사용하는 자연수는 N 이하여야 한다.
예를 들어 15를 나타내는 방법은 15, 7 + 8, 4 + 5 + 6, 1 + 2 + 3 + 4 + 5 이다.
반면, 10을 나타내는 방법은 10, 1 + 2 + 3 + 4 이다.
N을 입력받아 연속된 자연수의 합으로 나타내는 가짓수를 출력하는 프로그램을 작성하시오.

입력:
1번째 줄에 정수 N이 주어진다

출력:
입력된 자연수 N을 연속된 자연수의 합으로 나타내는 가짓수를 출력한다

투 포인터 이동 원칙:
sum > N: sum = sum - start_index; start_index++;
sum < N: end_index++; sum = sum + end_index;
sum == N: end_index++; sum = sum + end_index; count++;
*/

#include <iostream>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    int count = 1, startIndex = 1, endIndex = 1, sum = 1;

    cin >> N;

    while (endIndex != N)
    {
        // 답을 찾은 경우
        if (sum == N) 
        {
            endIndex++;
            sum += endIndex;
            count++;
        }
        // 현재 합이 답보다 큰 경우
        else if (sum > N)
        {
            sum -= startIndex;
            startIndex++;
        }
        // 현재 합이 답보다 작은 경우
        else if (sum < N)
        {
            endIndex++;
            sum += endIndex;
        }
    }
    cout << count << "\n";
    return (0);
}