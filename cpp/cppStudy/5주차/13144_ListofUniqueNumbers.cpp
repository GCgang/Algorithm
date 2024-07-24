// https://www.acmicpc.net/problem/13144
/*
문제:
길이가 N인 수열이 주어진다
연속한 1개 이상의 수를 뽑았을 때,
같은 수가 여러 번 등장하지 않는 경우의 수를 구하는 프로그램을 작성하시오

입력:
첫 번째 줄에는 수열의 길이 N이 주어진다 (1 <= N <= 100,000)
두 번째 줄에는 수열을 나타내는 N개의 정수가 주어진다.
수열에 나타나는 수는 모두 1 이상 100,000 이하이다

출력:
조건을 만족하는 경우의 수를 출력한다

ex:
입력
5
1 2 3 4 5

5
1 1 1 1 1

출력
15

5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> nums(N);
    bool checked[100001] = {false};

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    long long ret = 0;
    int e = 1;
    checked[nums[0]] = true; // 첫 번 째 원소의 등장 체크

    for (int s = 0; s < N; ++s) // 모든 시작점에 대해 반복
    {
        while(e < N) // 끝 인덱스가 수열의 끝에 도달할 때까지 반복
        {
            if (checked[nums[e]]) // 등장했던 수면 반복 종료
                break;
            checked[nums[e++]] = true; // 등장하지 않은수면 등장 체크 및 인덱스 ++
        }
        ret += e - s; // 현재 시작점에서 유니크한 부분 수열의 개수를 ret에 추가
        checked[nums[s]] = false; // 시작점의 숫자 등장 체크를 헤제
    }
    cout << ret << "\n";
    return 0;
}