// https://www.acmicpc.net/problem/4659
/*
문제:
패스워드 생생기를 만드려고 한다. 생성기를 테스트해보고 생성되는 패스워드의 품질을 평가해야 한다.
높은 품질을 가진 비밀번호의 조건은 다음과 같다.
1. 모음(a, e, i, o, u)하나를 반드시 포함해야 한다
2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
3. 같은 글자가 연속적으로 두번 오면 안되나, ee와 oo는 허용한다.

입력:
입력은 여러개의 테스트 케이스로 이루어져 있다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 테스트할 패스워드가 주어진다.
마지막 테스트 케이스는 end이며, 패스워드는 한글자 이상 20글자 이하의 문자열이다.
또한 패스워드는 대문자를 포함하지 않는다.

출력:
각 테스트 케이스를 '예제 출력'의 형태에 기반하여 품질을 평가하여라.

ex:
입력         출력
a           <a> is acceptable.
tv          <tv> is not acceptable.
ptoui       <ptoui> is not acceptable.
bontres     <bontres> is not acceptable.
zoggax      <zoggax> is not acceptable.
wiinq       <wiinq> is not acceptable.
eep         <eep> is acceptable.
houctuh     <houctuh> is acceptable.
end

consonant 모음
vowel 자음
*/


#include <iostream>
#include <string>
using namespace std;

// 모음 확인 함수
bool isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    string pw;

    while (cin >> pw)
    {
        if (pw == "end")
            break ;

        bool flag = false;
        bool is_include = false;
        int conCnt = 0, vCnt = 0;

        for (int i = 0; i < pw.size(); ++i)
        {
            if (isVowel(pw[i])) // 모음인 경우
            {
                conCnt++; // 연속된 자음 카운터 증가
                vCnt = 0; // 연속된 모음 카운터 초기화
                is_include = true; // 모음 포함 체크
            }
            else
            {
                vCnt++; // 연속된 모음 카운터 증가
                conCnt = 0; // 연속된 자음 카운터 초기화
            }

            // 연속된 모음 혹은 자음이 3개 이상인 경우 유효하지 않은 패스워드로 표시
            if (conCnt >= 3 || vCnt >= 3)
            {
                flag = true;
            }
            // 같은 문자가 연속으로 두 번 오는 경우 (ee, oo 제외)
            if (i > 0 && pw[i] == pw[i - 1] && pw[i] != 'e' && pw[i] != 'o')
            {
                flag = true;
            }
        }
        // 모음이 하나도 포함되지 않은 경우
        if (is_include == false)
            flag = true;
        if (!flag)
            cout << "<" << pw << ">" << " is acceptable.\n";
        else
            cout << "<" << pw << ">" << " is not acceptable.\n";
    }
    return 0;
}

