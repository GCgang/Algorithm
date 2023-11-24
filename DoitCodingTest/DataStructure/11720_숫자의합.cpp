// https://www.acmicpc.net/problem/11720
#include <iostream>
using namespace std;

/*
문제:
N개의 숫자가 공백 없이 쓰여 있다. 이 숫자를 모두 합해 출력하는 프로그램을 작성하시오.

입력:
1번째 줄에 숫자의 개수 N(1 <= 100)
2번째 줄에 숫자 N개가 공백없이 주어진다.

출력:
입력으로 주어진 숫자 N개의 합을 출력한다.
*/

int main()
{
    int N = 0;
    string numbers;

    cin >> N;
    cin >> numbers;

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += (numbers[i] - '0');
    }
    cout << sum << endl;
    return 0;
}