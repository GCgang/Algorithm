// https://www.acmicpc.net/problem/17298
/*
문제:
크기가 N인 수열 A = A1, A2, ... An이 있다.
수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰수 중에서 가장 왼쪽에 있는수를 의미한다.
그러한 수가 없는 경우에는 오큰수는 -1이다.
예를 들어 A = [3, 5, 2, 7]인 경우
NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1 이다.
A[9, 5, 4, 8]인 경우
NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1 이다.

입력:
첫째 줄에 수열 A의 크기 N(1 <= N <= 1,000,000)이 주어진다
둘째 줄에 수열 A의 원소 (A1, A2, ..., An) (1 <= Ai <= 1,000,000)이 주어진다.

출력:
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다

ex:
입력         출력
4           5 7 7 -1
3 5 2 7

4           -1 8 8 -1
9 5 4 8 

스택에 새로 들어오는 수가 top에 존재하는 수보다 크면 그 수는 오큰수가 된다
오큰수를 구한 후 수열에서 오큰수가 존재하지 않는 숫자에 -1을 출력한다.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> numArray(N, 0);
    vector<int> answer(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> numArray[i];
    
    stack<int> stk;

    for(int i = 0; i < N; ++i)
    {
        // 스택이 비지 않고 현재 수열이 top 위치의 값보다 크면
        while (!stk.empty() && numArray[stk.top()] < numArray[i])
        {
            answer[stk.top()] = numArray[i];// 정답 배열에 오큰수를 현재 수열로 저장
            stk.pop();
        }
        stk.push(i);
    }

    while (!stk.empty())
    {
        answer[stk.top()] = -1;
        stk.pop();
    }

    for (int i = 0; i < N; ++i)
        cout << answer[i] << " ";
    return 0;
}