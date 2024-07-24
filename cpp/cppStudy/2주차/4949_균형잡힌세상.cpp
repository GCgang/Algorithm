// https://www.acmicpc.net/problem/4949
/*
문제:
문자열에 포함되는 괄호는 소괄호 ("()") 와 대괄호 ("[]")로 2종류이고,
문자열이 균형을 이루는 조건은 아래와 같다
1. 모든 왼쪽 소괄호 "("는 오른쪽 소괄호 ")"와만 짝을 이뤄야 한다.
2. 모든 왼쪽 대괄호 "["는 오른쪽 대괄호 "]"와만 짝을 이뤄야 한다.
3. 모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
4. 모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
5. 짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.
문자열이 주어졌을 때, 균형잡힌 문자열인지 아닌지 판단해보자

입력:
각 문자열은 마지막 글자를 제외하고 영문 알파벳, 공백, 소괄호, 대괄호로 이루어져 있으며. 온점 (".")으로 끝나고 길이는 100글자보다 작거나 같다.
입력의 종료조건으로 맨 마지막에 온점 하나가 들어온다.

출력:
각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력한다

ex:
입력
So when I die (the [first] I will see in (heaven) is a score list).
[ first in ] ( first out ).
Half Moon tonight (At least it is better than no Moon at all].
A rope may form )( a trail in a maze.
Help( I[m being held prisoner in a fortune cookie factory)].
([ (([( [ ] ) ( ) (( ))] )) ]).
 .
.
출력
yes
yes
no
no
no
yes
yes
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{

    while (true)
    {
        string s;
        stack<char> stk;

        getline(cin, s);
        if (s == ".")
            break;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[')
                stk.push(s[i]);
            else if (stk.size() && stk.top() == '(' && s[i] == ')')
                stk.pop();
            else if (stk.size() && stk.top() == '[' && s[i] == ']')
                stk.pop();
            else if (s[i] == ')' || s[i] == ']')
                stk.push(s[i]);

        }
        if (stk.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}