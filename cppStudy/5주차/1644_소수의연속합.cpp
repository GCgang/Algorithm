// https://www.acmicpc.net/problem/1644
/*
문제:
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다.
몇 가지 자연수의 예를 들어 보면 다음과 같다
    - 3 : 3 (한가지)
    - 41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세가지)
    - 53 : 5+7+11+13+17 = 53 (두가지)
하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데,
20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다.
또한 한 소수는 반드시 한 번만 덧섬에 사용될 수 있기 때문에,
3+5+5+7과 같은 표현도 적합하지 않다
자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오

입력:
첫째 줄에 자연수 N이 주어진다 (1 <= N <= 4,000,000)

출력:
첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다

ex:
입력
20

3

41

출력
0

1

2


N보다작은 소수를 모두 구한다
소수들의 구간합 배열을 구한다
구간합 중에 N과 같은 수가 있는지 구한다
만약 있다면 몇번 더해야 그 수가 되는지를 구해서 출력한다
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    
    for (int i = 3; i * i <= num; i+=2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int N;
    vector<int> primeNums;

    cin >> N;

    for (int i = 2; i <= N; ++i)
    {
        if (isPrime(i))
        {
            primeNums.push_back(i);
        }
    }

    int s = 0, e = 0, sum = 0, ret = 0;
    while (true)
    {
        if (sum >= N)
            sum -= primeNums[s++]; // 합이 N 이상이면 시작점을 오른쪽으로 이동
        else if (e == primeNums.size())
            break; // 끝 점이 벡터의 끝에 도달하면 종료
        else
            sum += primeNums[e++]; // 그렇지 않으면 끝 점을 오른쪽으로 이동하며 합을 증가
        if (sum == N)
            ret++; // 현재의 합이 N과 같다면 경우의 수 증가
    }
    cout << ret << "\n";
    return 0;
}
