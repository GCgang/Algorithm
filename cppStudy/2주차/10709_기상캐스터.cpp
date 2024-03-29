// https://www.acmicpc.net/problem/10709
/*
문제:
JOI시는 남북방향이 H킬로미터, 동서방향이 W킬로미터인 직사각형 모양이다.
JOI시는 가로와 세로의 길이가 1킬로미터인 H x W 개의 작은 구역들로 나뉘어 있다.
북쪽으로부터 i번쨰, 서쪽으로부터 j번쨰에 있는 구역을 (i,j)로 표시한다.
각 구역의 하늘에는 구름이 있을 수도, 없을 수도 있다.
모든 구름은 1분이 지날 떄마다 1킬로미터씩 동쪽으로 이동한다.
오늘은 날씨가 정말 좋기 때문에 JOI시의 외부에서 구름이 이동해오는 경우는 없다
지금 각 구역의 하늘에 구름이 있는지 없는지를 알고 있다.
기상청에서 일하고 있는 여러분은 각 구역에 대해서 지금부터 몇 분뒤 처음으로 하늘에 구름이 오는지를 예측하는 일을 맡았다.
각 구역에 대해서 지금부터 몇 분뒤 처음으로 하늘에 구름이 오는지를 구하여라

입력:
입력은 1 + H 행으로 주어진다.
첫 번째 행에는 정수 H, W (1 <= H <= 100, 1 <= W <= 100)가 공백을 사이에 주고 주어진다.
이것은 JOI시가 H x W 개의 작은 구역으로 나뉘어 있다는 것을 의미한다.
이어진 H 개의 행의 i번째 행(1 <= i <= H)에는 W문자의 문자열이 주어진다.
W개의 문자 중 j번째 문자(1 <= j <= W)는, 구역(i,j)에 지금 구름이 떠 있는지 아닌지를 나타낸다.
구름이 있는 경우에는 영어 소문자 'c'가, 구름이 없는 경우에는 문자 '.'가 주어진다.

출력:
출력은 H 행으로, 각 행에는 공백으로 구분된 W 개의 정수를 출력한다.
출력의 i번째 행 j번째 정수 (1 <= i <= H, 1 <= j <= W)는, 지금부터 몇 분후에 처음으로 구역 (i,j)에 구름이 뜨는지를 표시한다.
단, 처음부터 구역(i,j)에 구름이 떠 있었던 경우에는 0을, 몇 분이 지나도 구름이 뜨지 않을 경우에는 -1을 출력한다.

ex:
입력        출력
3 4        0 1 2 0  
c..c      -1 -1 0 1
..c.      -1 -1 -1 -1
....

1. 행을 기준으로 c가 아직 한번도 안나왔다면 -1
2. c라면 0 출력 및 c가 나왔다는 플래그 on
3. c가 나왔다는 플래그가 있고 c가 아니라면 이전값 + 1
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H, W;

    cin >> H >> W;

    char JOI[H][W];
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> JOI[i][j];
        }
    }

    for (int i = 0; i < H; ++i)
    {
        bool cFlag = false;
        int num = 0;
        for (int j = 0; j < W; ++j)
        {
            if (JOI[i][j] != 'c' && cFlag == false)
                cout << -1 << " ";
            else if (JOI[i][j] == 'c')
            {
                cout << 0 << " ";
                cFlag = true;
                num = 0;
            }
            else if (JOI[i][j] != 'c' && cFlag == true)
                cout << ++num << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
다른 풀이
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H, W;

    cin >> H >> W;
    vector<vector<int> > JOI(H, vector<int>(W, -1));

    for (int i = 0; i < H; ++i)
    {
        string row;
        cin >> row;
        int time = -1;

        for(int j = 0; j < W; ++j)
        {
            if (row[j] == 'c')
            {
                time = 0;
                JOI[i][j] = 0;
            }
            else if (time != -1)
            {
                time++;
                JOI[i][j] = time;
            }
        }
    }


    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << JOI[i][j] << " ";
        }
        cout << "\n";
    }
*/