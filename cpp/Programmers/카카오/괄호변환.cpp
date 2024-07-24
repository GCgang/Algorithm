// https://school.programmers.co.kr/learn/courses/30/lessons/60058

#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isCorrect(string& p)
{
    // 짝 확인
    stack<char> stk;
    for (int i = 0; i < p.length(); ++i)
    {
        if (p[i] == '(')
            stk.push(p[i]);
        else if (!stk.empty() && p[i] == ')' && stk.top() == '(')
            stk.pop();
        else
            return false;
    }

    return true;
}

int balanceIDX(string &p)
{
    int openCnt = 0;
    int closeCnt = 0;
    int idx = 0;
    
    for (int i = 0; i < p.length(); ++i)
    {
        if (p[i] == '(')
            openCnt++;
        if (p[i] == ')')
            closeCnt++;
        
        if (openCnt == closeCnt)
        {
            idx = i + 1;
            break;
        }
    }
    return idx;
}

string solution(string p)
{
    string ans = "";
    // 1. 빈 문자열인 경우, 빈 문자열 반환
    if (p == "") 
        return (p);

    // 2. 균형잡힌 괄호 문자열 u, v로 분리
    int idx = balanceIDX(p);
    string u = p.substr(0, idx);
    string v = p.substr(idx);
    if (isCorrect(u)) // 3.u가 올바른 괄호 문자열인 경우
    {
        return u + solution(v); // v에 대해 재귀적으로 수행
    }
    else // 4. 올바른 괄호 문자열이 아닌 경우
    {
        ans = "(" + solution(v) + ")";
        // 4.4 u의 첫 번쨰와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 붙이기
        u.erase(u.begin());
        u.erase(u.end() - 1);
        for (int i = 0; i < u.length(); ++i)
        {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        ans += u;

    }
    // 균형잡힌 괄호 문자열 이면 올바른 문자열로 변환

    
    return ans;
}