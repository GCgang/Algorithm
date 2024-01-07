// https://www.acmicpc.net/problem/1541
/*
문제:
양수와 + , - 그리고 괄호를 이용해 어떤 수식을 만들었다
괄호를 모두 지우고, 다시 괄호를 적절히 넣어 이 수식의 값을 최소로 만들려고 한다
이렇게 수식의 괄호를 다시 적절하게 배치해 수식의 값을 최소로 만드는 프로그램을 작성하시오

입력:
1번째 줄에 식이 주어진다
식은 0 ~ 9, + 그리고 - 만으로 이루어져 있다
가장 처음과 마지막 문자는 숫자다
연속해서 2개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다
수는 0으로 시작할 수 있다.
입력으로 주어지는 식의 길이는 50보다 작거나 같다

출력:
1번쨰 줄에 정답을 출력한다

ex:
입력                              출력
100-40+50+74-30+29-45+43+11     -222
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter);
int mySum(string expression);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    string expression;

    cin >> expression;

    vector<string> str = split(expression, '-');

    for (int i = 0; i < str.size(); ++i)
    {
        int temp = mySum(str[i]);
        
        if (i == 0)
            answer += temp; // 앞에 것만 더하기
        else
            answer -= temp; // 뒤에 부분은 더한 값을 빼 줌 
    }
    cout << answer << "\n";

    return 0;
}

vector<string> split(string expression, char delimiter)
{
    vector<string> result;
    stringstream myStream(expression);
    string token;

    while (getline(myStream, token, delimiter))
    {
        result.push_back(token);
    }
    return result;
}

int mySum(string expression)
{
    int sum = 0;
    vector<string> temp = split(expression, '+');

    for (int i = 0; i < temp.size(); ++i)
    {
        sum += stoi(temp[i]);
    }
    return sum;
}