#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int N;
char school[7][7];
bool flag = false;
vector<pair<int, int> > teacher;
vector<pair<int, int> > space;
vector<pair<int, int> > selected;


bool check()
{
    for (int i = 0; i < teacher.size(); ++i)
    {
        int y = teacher[i].first;
        int x = teacher[i].second;

        for (int i = 0; i < 4; ++i)
        {
            int ny = y;
            int nx = x;
            while (true) // 한방향을 모두 탐색한다
            {
                ny += dy[i];
                nx += dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                    break;
                if (school[ny][nx] == 'S') // 학생 만다면 감시가능
                    return false;
                if (school[ny][nx] == 'O') // 벽 만날시 중단
                    break;
            }
        }
    }
    return true; // 모든 선생님의 감시를 피함
}

// void combi(int start)
// {
//     if (flag)
//         return ;
//     if (selected.size() == 3) // 선택된 벽의 위치가 3개라면
//     {
//         // 장애물 생성
//         for (int i = 0; i < 3; ++i) {
//             school[selected[i].first][selected[i].second] = 'O';
//         }
//         // 감시하기
//         if (check())
//             flag = true;
//         // 장애물 허물기
//         for (int i = 0; i < 3; ++i) {
//             school[selected[i].first][selected[i].second] = 'X';
//         }
//     }

//     for (int i = start + 1; i < space.size(); ++i)
//     {
//         selected.push_back(space[i]); // 장애물이 들어갈 수 있는 좌표를 넣어줌
//         combi(i);
//         selected.pop_back();
//     }
// }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> school[i][j];
            if (school[i][j] == 'X')
                space.push_back(make_pair(i, j));
            else if (school[i][j] == 'T')
                teacher.push_back(make_pair(i, j));
        }
    }

    // combi(-1);


    // 빈 공간에서 3개를 뽑는 모든 조합 확인
    vector<bool> selected(space.size());
    fill(selected.end() - 3, selected.end(), true);
    do
    {  
        // 장애물 만들기
        for (int i = 0; i < space.size(); ++i)
        {
            if (selected[i])
            {
                int y = space[i].first;
                int x = space[i].second;
                school[y][x] = 'O';
            }
        }
        // 감시하기
        if (check())
        {
            flag = true;
            break;
        }
        // 장애물 지우기
        for (int i = 0; i < space.size(); ++i)
        {
            if (selected[i])
            {
                int y = space[i].first;
                int x = space[i].second;
                school[y][x] = 'X';
            }
        }
        
    } while (next_permutation(selected.begin(), selected.end()));
    
    if (flag)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    return 0;
}
