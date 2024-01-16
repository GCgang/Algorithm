// https://www.acmicpc.net/problem/9375
/*
문제:
해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다
예를 들어 오늘 해빈이가 안경, 코트, 상의, 신발을 입었다면,
다음날은 바지를 추가로 입거나 안경대신 렌즈를 착용하거나 해야한다
해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?

입력:
첫째 줄에 테스트 케이스가 주어진다 (최대 100개)
각 테스트 케이스의 첫째 줄에는 해빈이가 가진 의상의 수 n(0 <= n <= 30)이 주어진다
다음 n개에는 해빈이가 가진 의상의 이름과 의상의 종류가 공백으로 구분되어 주어진다. 같은 종류의 의상은 하나만 입을 수 있다
모든 문자열은 1이상 20이하의 알파벳 소문자로 이루어져있으며 같은 이름을 가진 의상은 존재하지 않는다

출력:
각 테스트 케이스에 대해 해빈이가 알몸이 아닌 상태로 의상을 입을 수 있는 경우를 출력하시오

ex:
입력                    출력
2                       5
3                       3
hat headgear
sunglasses eyewear
turban headgear
3
mask face
sunglasses face
makeup face
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int testCase;

    cin >> testCase;

    while(testCase--)
    {
        int N;
    
        cin >> N;
        map<string, int> clothes;

        // 의상의 종류가 몇개 있는지 카운팅
        for (int i = 0; i < N; ++i)
        {
            string name, type;
            cin >> name >> type;
            clothes[type]++;
        }

        long long res = 1;
        // 옷 종류의 개수 + 안입는 경우의 수를 1 더해서 옷 종류 만큼의 경우의 수를 구하기
        for (auto i : clothes)
        {
            res *= static_cast<long long>(i.second + 1);
        }
        cout << res - 1 << "\n"; // 아무 의상도 입지 않은 경우 1을 뺴줌
    }
    return 0;
}