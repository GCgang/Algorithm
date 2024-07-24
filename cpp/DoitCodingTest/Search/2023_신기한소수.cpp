// https://www.acmicpc.net/problem/2023
/*
문제:
수빈이가 세상에서 가장 좋아하는 것은 소수이고, 취미는 소수를 가지고 노는 것이다.
요즘 수분이가 가장 관심있어 하는 소수는 7331이다
7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다.
즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다
수빈이는 이런 숫자를 신기한 소수라고 이름을 붙였다
수빈이는 N자리의 숫자 중에서 어떤 수들이 신기한 소수인지 궁금해졌다.
N이 주어졌을 때, 수빈이를 위해 N자리 신기한 소수를 모두 찾아보자

입력:
1번째 줄에 N(1 <= N <= 8)이 주어진다

출력:
N자리 수 중에서 신기한 소수를 오름차순으로 정렬해서 한 줄에 하나씩 출력한다.

ex:
입력    출력
4       2333
        2339
        2393
        2399
        2939
        3119
        3137
        3733
        3739
        3793
        3797
        5939
        7193
        7331
        7333
        7393

소수: 1보다 큰 자연수 중 1과 자기 자신만을 약수로 가지는 수
*/

#include <iostream>
using namespace std;
void DFS(int num, int digit);
bool isPrime(int num);
static int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    return (0);
}

void DFS(int num, int digit)
{
    if (digit == N)
    {
        if (isPrime(num) == true)
        {
            cout << num << "\n";
        }
        return ;
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (isPrime(num * 10 + i) == true)
        {
            DFS(num * 10 + i, digit + 1);
        }
    }
}

bool isPrime(int num)
{
    for (int i = 2; i <= num / 2; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}