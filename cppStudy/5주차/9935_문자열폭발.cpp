// https://www.acmicpc.net/problem/9935
/*
문제:
상근이는 문자열에 폭발 문자열을 심어 놓았다
폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게 된다
폭발은 다음과 같은 과정으로 진행된다
    - 문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다
    - 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다
    - 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다
    - 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다
상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다.
남아있는 문자가 없는 경우가 있다.
이때는 "FRULA"를 출력한다
폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다

입력:
첫째 줄에 문자열이 주어진다. 문자열의 길이는 1보다 크거나 같고, 1,000,000보다 작거나 같다.
둘째 줄에 폭발 문자열이 주어진다. 길이는 1보다 크거나 같고, 36보다 작거나 같다.
두 문자열은 모두 알파벳 소문자와 대문자, 숫자 0, 1, ..., 9로만 이루어져 있다.

출력:
첫째 줄에 모든 폭발이 끝난 후 남은 문자열을 출력한다.

ex:
입력
mirkovC4nizCC44
C4

출력
mirkovniz

입력
12ab112ab2ab
12ab

출력
FRULA
*/

#include <iostream>
#include <string>
using namespace std;

// erase 사용 풀이
int main()
{
    string str, bomb, ret;

    cin >> str >> bomb;

    for (char c : str)
    {
        ret += c;
        // 폭발 문자열과 같거나 크다면 자를 수 있음
        if (ret.size() >= bomb.size())
        {
            // ex) mirkovC4
            // mirkovC4.substr(6(8-2), 2) -> C4 == bomb
            // mirkovC4.erase(6(8-2), 8) -> mirkovC4 - C4 -> mirkov
            if (ret.substr(ret.size() - bomb.size(), bomb.size()) == bomb)
                ret.erase(ret.end() - bomb.size(), ret.end());
        }
    }

    if (ret.empty())
        cout << "FRULA" << "\n";
    else
        cout << ret << "\n";
    return 0;
}


// // stack 사용 풀이
// #include <stack>
// #include <algorithm>
// int main()
// {

//     string str, bomb, ret;
//     stack<char> stk;

//     cin >> str >> bomb;

//     // 스택의 끝 지점이 폭발 문자열의 끝 값과 같다면 
//     for (char c : str)
//     {
//         stk.push(c);
//         if (stk.size() >= bomb.size())
//         {
//             if (stk.top() == bomb[bomb.size() - 1])
//             {
//                 string temp = "";

//                 for (char c : bomb)
//                 {
//                     temp += stk.top();
//                     stk.pop();
//                 }
//                 reverse(temp.begin(), temp.end());
//                 if (temp != bomb)
//                 {
//                     for (char c : temp)
//                     {
//                         stk.push(c);
//                     }
//                 }
//             }
//         }
//     }

//     if (stk.empty())
//         cout << "FRULA" << "\n";
//     else
//     {
//         while (stk.size())
//         {
//             ret += stk.top();
//             stk.pop();
//         }
//         reverse(ret.begin(), ret.end());
//         cout << ret << "\n";
//     }
//     return 0;
// }
