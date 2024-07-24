// https://www.acmicpc.net/problem/1439

/*
다솜이는 0과 1로만 이루어진 문자열 S를 가지고 있다.
다솜이는 이 문자열 S에 있는 모든 숫자를 전부 같게 만들려고 한다.
다솜이가 할 수 있는 행동은 S에서 연속된 하나 이상의 숫자를 잡고 모두 뒤집는 것이다.
뒤집은 것은 1을 0으로, 0을 1로 바꾸는 것을 의미한다
예를들어, S = 0001100일 때, 다음과 같다
    전체를 뒤집으면 1110011이 된다
    4번째 문자부터 5번째 문자까지 뒤집으면 1111111이 되어서 두 번 만에 모두 같은 숫자로 만들 수 있다.
하지만, 처음부터 4번째 문자부터 5번째 문자까지 문자를 뒤집으면 한 번에 0000000이 되어서 1번 만에 모두 같은 숫자로 만들 수 있다
문자열 S가 주어졌을 떄, 다솜이가 해야 하는 행동의 최소 횟수를 출력하세요

입력:
첫째 줄에 0과 1로만 이루어진 문자열 S가 주어진다
S의 길이는 100만보다 작다

출력:
첫째 줄에 다솜이가 해야 하는 행동의 최소 횟수가 출력한다

ex:
입력
0001100

출력
1

0이 나오는 영역 1이 나오는 영역을 비교하여 더 작은 영역을 출력
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int oneArea; // 1로 바꾸는 경우
int zeroArea; // 0으로 바꾸는 경우
int ret;

int main()
{
    cin >> s;

    // 처음 나온 영역 증가
    if (s[0] == '1')
        oneArea++;
    else
        zeroArea++;
    

    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] != s[i + 1]) // 영역이 바뀌면 바뀌는 곳의 영역 증가
        {
            if (s[i + 1] == '1')
                oneArea++;
            else
                zeroArea++;
        }
    }

    cout << min(oneArea, zeroArea);

    return 0;
}
