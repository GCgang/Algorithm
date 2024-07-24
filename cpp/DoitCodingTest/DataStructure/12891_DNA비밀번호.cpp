// https://www.acmicpc.net/problem/12891
/*
문제:
DNA 문자열은 모든 문자열에 등장하는 문자가 {'A', 'C', 'G', 'T'}인 문자열을 말한다.
예를 들어 "ACKA"는 DNA 문자열이 아니지만, "ACCA"는 DNA 문자열이다.
이런 신비한 문자열에 빠진 민호는 임의의 DNA 문자열을 만들고
만들어진 DNA 문자열의 부분 문자열을 비밀번호로 사용하기로 마음먹었다.
하지만 문제는 DNA 문자열의 부분 문자열을 뽑았을 때 "AAAA"와 같이 보안에 취약한 비밀번호가 만들어질 수 있기 떄문이다.
그래서 부분 문자열에서 등장하는 문자의 개수가 특정 개수 이상이어야 비밀번호로 사용할 수 있다는 규칙을 만들었다.
예를 들어 임의의 DNA 문자열이 "AAACCTGCCAA"이고, 민호가 뽑을 부분 문자열의 길이를 4라고 가정해 보자.
그리고 부분 문자열에 'A'는 1개 이상, 'C'는 1개 이상, 'G'는 1개 이상, 'T'는 0개 이상 등장해야 한다는 조건을 만족하지 못해 비밀번호로 사용할 수 없지만,
"GCCA"은 모든 조건을 만족하므로 비밀번호로 사용할 수 있다.
민호가 만든 임의의 DNA 문자열과 비밀번호로 사용할 부분 문자열의 길이 그리고 {'A', 'C', 'G', 'T'}가
각각 몇 번 이상 등장해야 비밀번호로 사용할 수 있는지, 순서대로 주어졌을 때 민호가 만들 수 있는 비밀번호의 종류의 수를 구하는 프로그램을 작성하시오.
단, 부분 문자열이 등장하는 위치가 다르면 부분 문자열의 내용이 같더라도 다른 문자열로 취급한다.

입력:
1번째 줄에 민호가 임의로 만든 DNA 문자열의 길이 |S|와 비밀번호로 사용할 부분 문자열의 길이 |P|가 주어진다 (1 <= |P| <= |S| <= 1,000,000)
2번째 줄에 민호가 임의로 만든 DNA 문자열이 주어진다.
3번째 줄에 부분 문자열에 포함돼야 할 {'A', 'C', 'G', 'T'}의 최소 개수가 공백 문자를 사이에 두고 각각 주어진다.
각각의 수는 |S|보다 작거나 같은 음이 아닌 정수로 총합은 |S|보다 작거나 같다는 것이 보장된다.

출력:
첫 번째 줄에 민호가 만들 수 있는 비밀번호 종류의 개수를 출력한다

ex:
입력                                                    출력
9 8         -> DNA 문자열의 길이, 부분 문자열의 길이            0
CCTGGATTG   -> DNA 문자열
2 0 1 1     -> 부분 문자열에 포함돼야 할 A,C,G,T의 최소 개수

입력                                                    출력
4 2                                                     2
GATA
1 0 0 1     
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << boolalpha;

    int strCount = 0, pwCount = 0;
    int checkArray[4] = {0};
    string input;
    string DNA;

    cin >> strCount >> pwCount;
    cin >> DNA;

    for ( int i = 0; i < 4; ++i)
    {
        cin >> checkArray[i]; // 1 0 0 1
    }
    // A C G T
    int pwArray[4] = {0}; 

    for (int i = 0; i < pwCount; ++i)
    {   
        if (DNA[i] == 'A')
            pwArray[0]++;
        else if (DNA[i] == 'C')
            pwArray[1]++;
        else if (DNA[i] == 'G')
            pwArray[2]++;
        else if (DNA[i] == 'T')
            pwArray[3]++;
    } // 1 0 1 0

    int result = 0;
    bool check = true;

    for (int i = 0; i < 4; ++i)
    {
        if (checkArray[i] > pwArray[i])
        {
            check = false;
            break;
        }
    }
    if (check)
    {
        result++;
    }

    // ACGT
    // GATA
    // GA 1 0 1 0  0 0 1 0
    // AT 1 0 0 1
    // TA 1 0 0 1

    // An 1 0 0 1
    for (int i = 1; i <= (strCount - pwCount); ++i)
    {
        if (DNA[i - 1] == 'A')
            pwArray[0]--;
        else if (DNA[i - 1] == 'C')
            pwArray[1]--;
        else if (DNA[i - 1] == 'G')
            pwArray[2]--;
        else if (DNA[i - 1] == 'T')
            pwArray[3]--;
        
        if (DNA[i + pwCount - 1] == 'A')
            pwArray[0]++;
        else if (DNA[i + pwCount - 1] == 'C')
            pwArray[1]++;
        else if (DNA[i + pwCount - 1] == 'G')
            pwArray[2]++;
        else if (DNA[i + pwCount - 1] == 'T')
            pwArray[3]++;
        
        check = true;
        for (int j = 0; j < 4; ++j)
        {
            if (checkArray[j] > pwArray[j])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            result++;
        }
    }
    cout << result << "\n";

    return 0;
}