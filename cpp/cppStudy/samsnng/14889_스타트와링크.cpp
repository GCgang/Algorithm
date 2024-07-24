// https://www.acmicpc.net/problem/14889

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ret = 999999999;
int stat[22][22];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> stat[i][j];
        }
    }

    vector<int> team(N, 1); // N명중 2팀으로 나눔
    fill(team.begin(), team.begin() + N - N/2, 0); // 0=스타트팀 , 1=링크 팀
    do
    {
        int diff = 0; // 능력치 차이
        for (int i = 0; i < N; ++i)
        {
            for (int j = i+1; j < N; ++j) // 각 쌍을 한번씩만 고려
            {
                if (team[i] != team[j]) // i, j가 다른 팀이면 무시
                    continue;
                if (team[i] == 0) // 스타트 팀이라면
                    diff += (stat[i][j] + stat[j][i]); // 스타트 팀의 능력치를 더함
                else // 링크 팀이라면
                    diff -= (stat[i][j] + stat[j][i]); // 링크 팀의 능력치를 뺴서 계산

            }
        }
        ret = min(ret, abs(diff));
    } while (next_permutation(team.begin(), team.end()));

    cout << ret << "\n";
    return 0;
}