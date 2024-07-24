// https://www.acmicpc.net/problem/2870
/*
문제:
선생님이 상근이에게 준 종이에는 숫자와 알파벳 소문자로 되어있는 글자가 N줄있다.
상근이는 여기서 숫자를 모두 찾은 뒤, 이 숫자를 비내림차순으로 정리해야한다.
숫자의 앞에 0이있는 경우에는 정리하면서 생략할 수 있다.
글자를 살펴보다가 숫자가 나오는 경우에는, 가능한 가장 큰 숫자를 찾아야 한다.
즉, 모든 숫자의 앞과 뒤에 문자가 있거나, 줄의 시작 또는 끝이어야 한다
예를 들어, 01a2b3456cde478에서 숫자를 찾으면 1, 2, 3456, 478이다
선생님이 준 종이의 내용이 주어젔을 때, 상근이의 숙제를 대신하는 프로그램을 작성하시오.

입력:
첫째 줄에 종이의 줄의 개수 N이 주어진다(1 <= N <= 100)
다음 N개의 줄에는 각 줄의 내용이 주어진다. 각 줄은 최대 100글자이고, 항상 알파벳 소문자와 숫자로만 이루어져 있다.

출력:
종이에서 찾은 숫자의 개수를 M개라고 하면, 출력은 M줄로 이루어져야 한다.
각 줄에는 종이에서 찾은 숫자를 하나씩 출력해야 한다.
이떄, 비내림차순으로 출력해야 한다. 비내림차순은 내림차순의 반대인 경우인데, 다음 수가 앞의 수보다 크거나 같은 경우를 말한다.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 문자열에서 앞에있는 0 제거 함수
void go(string& temp, vector<string>& numArray)
{
    while (true)
    {
        if (temp.size() && temp.front() == '0')
            temp.erase(temp.begin());
        else
            break;
    }
    // 문자열이 비어있으면 '0' 추가 ex) 0000
    if (temp.size() == 0)
        temp = "0";
    numArray.push_back(temp);
    temp = "";
}

bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b; // 길이가 같을 때 사전순으로 비교
    return a.size() < b.size(); // 길이가 다를 때는 길이가 짧은 순서대로 정렬
}

int main()
{
    int N;
    string str;
    vector<string> numArray;

    cin >> N;
    while (N--)
    {
        cin >> str;
        string temp = "";
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
                temp += str[i];
            else if (temp.size())
                go(temp, numArray);
        }
        // 마지막 숫자 처리
        if (temp.size())
            go(temp, numArray);
    }
    sort(numArray.begin(), numArray.end(), cmp);
    for (string num : numArray)
        cout << num << "\n";

    return 0;
}