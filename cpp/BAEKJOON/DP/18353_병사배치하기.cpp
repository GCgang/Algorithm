// https://www.acmicpc.net/problem/18353

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> soldier(N);
    vector<int> dp(N, 1);
    for (int i = 0; i < N; ++i)
        cin >> soldier[i];
    
    // LDS(가장 긴 감소하는 부분 수열) 길이 계산
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            // 현재 병사(i)의 전투력이 이전 병사(j)의 전투력보다 작고,
            // 이전 병사(j)까지의 최대 LDS 길이에 현재 병사(i)를 추가했을 때
            // 현재 병사(i)까지의 최대 LDS 길이가 더 커지는 경우, outside[i]를 업데이트
            if (soldier[j] > soldier[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    // 열외해야 하는 병사의 최소 수 = 전체 병사 수 - LDS의 최대 길이

    cout << N - *max_element(dp.begin(), dp.end());
    return 0;
}