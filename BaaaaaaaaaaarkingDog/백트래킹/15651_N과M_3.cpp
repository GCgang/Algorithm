// https://www.acmicpc.net/problem/15651
/*
문제:
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.

입력:
첫째 줄에 자연수 N과 M이 주어진다 (1 <= M <= N <= 7)

출력:
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다.
중복되는 수열을 여러 번 출력하면 안되며, 
각 수열은 공백으로 구분해서 출력해야 한다
수열은 사전 순으로 증가하는 순서로 출력해야 한다

ex:
입력
3 1

출력
1
2
3
*/

// 1부터 N까지 자연수 중에서 M개를 고른 수열
// 같은 수를 여러 번 골라도 된다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];

void func(int k)
{
    if (k == M) // m개를 모두 골랐으면
    {
        for (int i = 0; i < M; ++i) // 조합 개수 만큼 돌면서 출력
            cout << arr[i] << " ";
        cout << "\n";
        return ;
    }
    for (int i = 1; i <= N; ++i) // N 만큼 돌면서 1일때 2..3..4 등의 조합을 구한다
    {
        arr[k] = i; // k번째 수를 i로 한다
        func(k+1); // 다음 위치로 재귀 호출
    }

}

int main()
{
    cin >> N >> M;
    func(0);
    return 0;
}