// https://www.acmicpc.net/problem/2910
/*
문제:
메시지는 숫자 N개로 이루어진 수열이고, 숫자는 모두 C보다 작거나 같다.
창영이는 이 숫자를 자주 등장하는 빈도순대로 정렬하려고 한다.
만약, 수열의 두 수 X와 Y가 있을 때,
X가 Y보다 수열에서 많이 등장하는 경우에는 X가 Y보다 앞에 있어야 한다.
만약, 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 한다
이렇게 정렬하는 방법을 빈도 정렬이라고 한다
수열일 주어졌을 떄, 빈도 정렬을 하는 프로그램을 작성하시오

입력:
첫째 줄에 메시지의 길이 N과 C가 주어진다 (1 <= N <= 1,000, 1 <= C <= 1,000,000,000)
둘째 줄에 메시지 수열이 주어진다

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> numCountMap;
map<int, int> numFirstDirectionMap;

// 정렬 기준 정의
bool compare(int a, int b)
{
    // 빈도를 비교해서 더 많이 등장한 숫자가 앞으로 오도록 한다
    if (numCountMap[a] != numCountMap[b])
        return (numCountMap[a] > numCountMap[b]);
    // 빈도가 같다면 첫 등장 위치가 더 앞인 숫자가 앞으로 오도록 한다
    return (numFirstDirectionMap[a] < numFirstDirectionMap[b]);
}

int main()
{
    int N, C;

    cin >> N >> C;

    vector<int> sequence(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> sequence[i];
        numCountMap[sequence[i]]++; //
        if (numFirstDirectionMap.find(sequence[i]) == numFirstDirectionMap.end()) // 등장 순서를 등록하는 배열에 해당 숫자가 없다면
        {
            numFirstDirectionMap[sequence[i]] = i + 1; // i를 1부터 시작하게 하기 위함
        }
    }
    
    sort(sequence.begin(), sequence.end(), compare);

    for (int i : sequence)
        cout << i << " ";

    return 0;
}