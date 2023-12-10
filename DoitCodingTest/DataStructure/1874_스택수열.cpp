// https://www.acmicpc.net/problem/1874
/*
문제:
1부터 n까지의 수를 스택에 저장하고 출력하는 방식으로 하나의 수열을 만들 수 있다
이때 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 가정한다.
수열이 주어졌을 때 이러한 방식으로 스택을 이용해 주어진 수열을 만들 수 있는지 확인하고 만들 수 있다면
어떤 순서로 push와 pop을 수행하여야 하는지 확인하는 프로그램을 작성해보자

입력:
1번째 줄에 수열의 개수 n(1 <= n <= 100,000)이 주어진다.
2번째 줄에는 수열을 이루는 1이상 n이하의 정수가 1개씩 순서대로 주어진다.
이때 같은 정수가 두 번 이상 나오지는 않는다

출력:
수열을 만들기 위한 연산 순서를 출력한다
push 연산은 +, pop 연산은 -로 출력하고, 불가능할 때는 NO를 출력한다.

ex:
입력                 출력
8 // 수열의 개수       +
4                   +
3                   +
6                   +
8                   -
7                   -
5                   +
2                   +
1                   -
                    +
                    +
                    -
                    -
                    -
                    -
                    -
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> sequence(N, 0);
    vector<char> answer;

    for (int i = 0; i < N; ++i)
    {
        cin >> sequence[i];
    }

    stack<int> Stack;
    int num = 1;
    bool valid = true;

    for (int i = 0; i < N; ++i)
    {
        int currentValue = sequence[i];
        // 현재 수열값 >= 오름차순 자연수: 값이 같아질 때까지 push() 수행
        if (currentValue >= num)
        {
            while (currentValue >= num)
            {
                Stack.push(num);
                num++;
                answer.push_back('+');
            }
            Stack.pop();
            answer.push_back('-');
        }
        // 현재 수열값 < 오름차순 자연수: pop()을 수행하여 수열 원소를 꺼냄
        else 
        {
            int topValue = Stack.top();
            Stack.pop();
            // 스택의 가장 위의 수가 만들어야 하는 수열의 수보다 크다면 수열 출력 불가능
            if (topValue > currentValue)
            {
                cout << "NO";
                valid = false;
                break ;
            }
            else
            {
                answer.push_back('-');
            }
        }
    }
    if (valid)
    {
        for (int i = 0; i < answer.size(); ++i)
        {
            cout << answer[i] << '\n';
        }
    }
    return 0;
}