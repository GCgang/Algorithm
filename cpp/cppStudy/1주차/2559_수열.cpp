// https://www.acmicpc.net/problem/2559
/*
문제:
측정한 온도가 어떤 정수의 수열로 주어졌을 때, 연속적인 며칠동안의 온도의 합이 가장 큰 값을 알아보고자 한다
예를 들어, 10일간의 온도가 주어졌을 때, 
3 -2 -4 -9 0 3 7 13 8 -3

모든 연속적인 이틀간의 온도의 합은 아래와 같다
1 -6 -13 -9 3 10 20 21 5
이때, 온도의 합이 가장 큰 값은 21이다

또 다른 예로 모든 연속적인 5일간의 온도의 합은 아래와 같다
-12 -12 -3 14 31 28
이때, 온도의 합이 가장 큰 값은 31이다

매일 측정한 온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 계산하는 프로그램을 작성하시오.

입력:
첫째 줄에는 두 개의 정수 N과 K가 한 개의 공백을 사이에 두고 순서대로 주어진다.
첫 번째 정수 N은 온도를 측정한 전체 날짜의 수이다.
N은 2이상 100,000 이하이다.
두 번째 정수 K는 합을 구하기 위한 연속적인 날짜의 수이다.
K는 1과 N 사이의 정수이다.
둘째 줄에는 매일 측정한 온도를 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다.
이 수들은 모두 -100 이상 100 이하이다

출력:
첫째 줄에는 입력되는 온도의 수열에서 연속적인 K일의 온도의 합이 최대가 되는 값을 출력한다

ex:
입력                                출력
10 2                                21
3 -2 -4 -9 0 3 7 13 8 -3

N : 1 ~ 10만
K : 1 ~ 10만 - 1(n사이 값)
온도 -100 ~ 100
연속된 온도의 합이 최대 되는 값 : prifixsum[i] = prifixsum[i - 1] + a[i] (구간 합 구하기)
문제의 최솟값은? -100짜리가 10만번 - 1번 나오는 경우 >>> -1000만 쯤
최대값은 어디서부터? 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, ret = -10000001;

    cin >> N >> K;

    vector<int> temperature(N + 1, 0);
    vector<int> sumArray(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        cin >> temperature[i];
        sumArray[i] = sumArray[i - 1] + temperature[i];
    }

    for (int i = K; i <= N; ++i)
    {
        ret = max(ret, sumArray[i] - sumArray[i - K]);
    }

    cout << ret << "\n";
    return 0;
}