// https://www.acmicpc.net/problem/11399
/*
문제:
ATM이 1대 있고, 이 ATM 앞에 N명의 사람들이 줄을 서 있다
사람은 1번에서 N번까지 번호가 매겨져 있으며, i번 사람이 돈을 인출하는 데 걸리는 시간은 P분이다.
사람들이 줄을 서는 순서에 따라서 돈을 인출하는 데 필요한 시간의 합이 달라진다.
예를 들어 총 5명이 있고, P1 = 3, P2 = 1, P3 = 4, P4 = 3, P5 = 2일 때를 생각해보자
[1, 2, 3, 4, 5]순서로 줄을 선다면 1번 사람은 3분 만에 돈을 뽑을 수 있다.
2번 사람은 1번사람이 뽑고 뽑아야 하므로 3 + 1 = 4분이 걸린다
3번은 1,2 번 사람이 뽑꼬 뽑아야 하므로 총 3 + 1 + 4 = 8분이 걸린다
이렇게 4번 사람은 3 + 1 + 4 + 3 = 11분, 5번 사람은 3 + 1 + 4 + 3 + 2 = 13분이 걸린다
즉, 각 사람이 돈을 인출하는 데 걸리는 시간의 합은 3 + 4 + 8 + 11 + 13 = 39분이다.
[2, 5, 1, 4, 3] 순서로 줄을 선다면
2번은 1분, 5번은 1 + 2 = 3분, 1번은 1 + 2 + 3 = 6분, 4번은 1 + 2 + 3 + 3 = 9분, 3번은 1 + 2 + 3 + 3 + 4 = 13분이 걸리므로
각 사람이 돈을 인출하는 데 필요한 시간의 합은 1 + 3 + 6 + 9 + 13 = 32분이다.
이 순서보다 모든 사람이 돈을 인출하는 데 필요한 시간이 짧을 수는 없다.
줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는 데 걸리는 시간 P가 주어졌을 때
각 사람이 돈을 인출하 데 필요한 시간의 합의 최솟값을 구하는 프로그램을 작성하시오.

입력:
1번째 줄에 사람의 수 N(1 <= N <= 1,000)
2번째 줄에 각 사람이 돈을 인출하는 데 걸리는 시간 P(1 <= P <= 1,000)가 주어진다

출력:
1번째 줄에 각 사람이 돈을 인출하는 데 필요한 시간의 합의 최솟값을 출력한다

ex:
입력                출력
5 // 데이터 개수      32
3 1 4 3 2

합배열 만드는 공식 prefixSum[i] = prefixSum[i - 1] + time[i]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> time(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        cin >> time[i];
    }
    // 정렬
    sort(time.begin(), time.end());

    vector<int> prefixSum(N + 1, 0);
    int sum = 0;

    // 합배열을 구하고 구한 값을 sum에 더해줌
    for (int i = 1; i <= N; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + time[i];
        sum += prefixSum[i];
    }
    cout << sum << "\n";
}