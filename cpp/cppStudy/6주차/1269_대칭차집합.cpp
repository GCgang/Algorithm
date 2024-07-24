// https://www.acmicpc.net/problem/1269
/*
문제:
자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다.
두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오.
두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.
예를 들어, A = {1,2,4}이고, B = {2,3,4,5,6}라고 할 떄,
A-B = {1}이고,
B-A = {3,5,6} 이므로,
대칭 차집합의 원소의 개수는 1 + 3 = 4이다

입력:
첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다.
둘째 줄에는 집합 A의 모든 원소가,
셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다.
각 집합의 원소의 개수는 200,000을 넘지 않으며,
모든 원소의 값은 100,000,000을 넘지 않는다.

출력:
첫째 줄에 대칭 차집합의 원소의 개수를 출력한다

ex:
입력
3 5
1 2 4
2 3 4 5 6

출력
4
*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, M, tmp, ret;
map<int, int> m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M; 

    for(int i = 0; i < N; ++i)
    {
        cin >> tmp;
        m[tmp]++;
    }
    for(int i = 0; i < M; ++i)
    {
        cin >> tmp;
        m[tmp]++;
    }

    // for (auto it : m)
    // {
    //     if (it.second == 1)
    //         ret++;
    // }

    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        if (it->second == 1)
            ret++;

    }
    cout << ret << "\n";

    return 0;
}