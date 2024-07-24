// https://www.acmicpc.net/problem/9996
/*
문제:
일치하는 파일 이름을 적절히 출력하지 못하는 버그가 생겼다
패턴은 알파벳 소문자 여러 개와 별표(*) 하나로 이루어진 문자열이다
파일 이름이 패턴에 일치하려면,
패턴에 있는 별표를 알파벳 소문자로 이루어진 임의의 문자열로 변환해 파일 이름과 같게 만들 수 있어야 한다
별표는 빈 문자열로 바꿀 수도 있다
예를들어, "abcd", "ad", "anestonestod"는 모두 패턴 "a*d"와 일치한다
하지만, "bcd"는 일치하지 않는다
패턴과 파일 이름이 모두 주어졌을 때, 각각의 파일 이름이 패턴과 일치하는지 아닌지를 구하는 프로그램을 작성하시오

입력:
첫째 줄에 파일의 개수 N이 주어진다 (1 <= N <= 100)
둘째 줄에는 패턴이 주어진다
패턴은 알파벳 소문자와 별표(아스키값 42) 한 개로 이루어져 있다
문자열의 길이는 100을 넘지 않으며, 별표는 문자열의 시작과 끝에 있지 않다
다음 N개 줄에는 파일 이름이 주어진다
파일 이름은 알파벳 소문자로만 이루어져 있고, 길이는 100을 넘지 않는다.

출력:
총 N개의 줄에 걸쳐서, 입력으로 주어진 i번째 파일 이름이 패턴과 일치하면 "DA"
일치하지 않으면 "NE"를 출력한다
참고로, "DA"는 크로아티아어로 "YES"를, "NE"는 "NO"를 의미한다

ex:
입력                출력
3                   DA
a*d                 DA
abcd                NE
anestonestod
facebook
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int N;
    string originStr;

    cin >> N;
    cin >> originStr;

    // 패턴 시작 부분 끝 부분 페어에 저장
    pair<string, string> pattern;
    pattern.first = originStr.substr(0, originStr.find('*')); // prefix
    pattern.second = originStr.substr(originStr.find('*') + 1); // suffix

    vector<string> inputString(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> inputString[i];
        // 반례 :  ab*ab 패틴이고 주어지는 문자열이 ab인 경우
        if (inputString[i].size() < pattern.first.size() + pattern.second.size())
        {
            cout << "NE" << "\n";
            continue;
        }
        // 입력한 문자열과 패턴의 시작 부분과 끝 부분이 일치하는지 확인
        if (inputString[i].substr(0, pattern.first.size()) == pattern.first && 
            inputString[i].substr(inputString[i].size() - pattern.second.size()) == pattern.second)
        {
            cout << "DA" << "\n";
        }
        else
        {   
            cout<< "NE" << "\n";
        }
    } 
    return 0;
}
