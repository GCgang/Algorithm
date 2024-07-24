// https://www.acmicpc.net/problem/1157
/*
문제:
알파벳 대소문자로 된 단어가 주어지면,
이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오
단, 대문자와 소문자를 구분하지 않는다

입력:
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다.
주어지는 단어의 길이는 1,000,000을 넘지 않는다

출력:
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.
단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다

ex:
입력
Mississipi

zZa

출력
?

Z

*/

#include <iostream>
#include <string>
#include <cstring> // memset
#include <cctype> // toupper
using namespace std;

int main()
{
    string str;

    cin >> str;

    int alpha[26];

    memset(alpha, 0, sizeof(alpha));

    for (char c : str)
    {
        c = toupper(c);
        alpha[c - 'A']++;
    }

    int maxCnt = -987654321, maxIdx = 0, multi = 0;

    for (int i = 0; i < 26; ++i)
    {
        if (alpha[i] > maxCnt)
        {
            maxCnt = alpha[i];
            maxIdx = i;
            multi = 1; // 최대값이 변경될 때 multi = 1
        }
        else if (alpha[i] == maxCnt) // 같은 최대값이 있으면 multi 증가
            multi++;
    }

    if (multi > 1)
        cout << "?" << "\n";
    else
        cout << (char)(maxIdx + 'A');
    return 0;
}