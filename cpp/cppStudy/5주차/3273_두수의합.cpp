// https://www.acmicpc.net/problem/3273
/*
문제:
n개의 서로 다른 양의 정수 a1, a2 ..., an으로 이루어진 수열이 있다
ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다.
자연수 x가 주어졌을 때, ai + aj = x(1 <= i < j <= n)을
만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오

입력:
첫째 줄에 수열의 크기 n이 주어진다
다음 줄에는 수열에 포함되는 수가 주어진다
셋째 줄에는 x가 주어진다 (1 <= n <= 100,000, 1 <= x <= 2,000,000)

출력:
문제의 조건을 만족하는 쌍의 개수를 출력한다

ex:
입력
9
5 12 7 10 9 1 2 3 11
13

출력
3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;

    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cin >> x;

    sort(nums.begin(), nums.end());
    int s = 0, e = n - 1, ret = 0;
    while (s < e)
    {
        if (nums[s] + nums[e] == x)
        {
            ret++;
            e--; // 더 작은 수와의 조합도 탐색하기 위해 e를 감소시킨다
        }
        else if (nums[s] + nums[e] > x)
            e--; // e를 감소시켜 합을 줄여, 더 작은 수를 가리킬 수 있게 한다
        else if (nums[s] + nums[e] < x)
            s++; // s를 증가시켜 합을 증가시킨다, 더 큰 수를 가리킬 수 있게 한다
    }

    cout << ret << "\n";

    return 0;
}