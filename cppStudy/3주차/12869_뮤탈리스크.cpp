// https://www.acmicpc.net/problem/12869
/*
문제:
수빈이는 뮤탈리스크 1개, 강호는 SCV N개가 남아있다.
각각의 SCV는 남아있는 체력이 주어져있으며, 뮤탈리스크를 공격할 수는 없다.
즉, 이 게임은 수빈이가 이겼다
뮤탈리스크가 공격을 할 때, 한 번에 세 개의 SCV를 공격할 수 있다.
	1. 첫번쨰 공격 -> SCV 체력 - 9
	2. 두번쨰 공격 -> SCV 체력 - 3
	3. 세번쨰 공격 -> SCV 체력 - 1
SCV의 체력이 0 또는 그 이하가 되어버리면, SCV는 그 즉시 파괴된다.
한 번의 공격에서 같은 SCV를 여러 번 공격할 수는 없다.
남아있는 SCV의 체력이 주어졌을 떄, 모든 SCV를 파괴하기 위해 공격해야 하는 횟수의 최솟값을 구하는 프로그램을 작성하시오

입력:
첫째 줄에 SCV의 수 N(1 <= N <= 3)이 주어진다.
둘쨰 줄에는 SCV N개의 체력이 주어진다.
체력은 60보다 작거나 같은 자연수이다.

출력:
첫째 줄에 모든 SCV를 파괴하기 위한 공격 횟수의 최솟값을 출력한다.

ex:
입력
3
12 10 4

출력
2
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int visited[61][61][61];
int scv[3];
int dmgs[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};

// scv 체력 구조체
struct scvHP
{
	int a, b, c;
};

queue<scvHP>q;

// 최소 공격 횟수를 구하는 함수
int solve(int a, int b, int c)
{
	visited[a][b][c] = 1;
	q.push({a, b, c});
	while(!q.empty())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (visited[0][0][0]) // 모든 scv 파괴된 경우
			break;
		for (int i = 0; i < 6; ++i)
		{
			int na = max(0, a - dmgs[i][0]); // 배열에서 음수 사용하면 안되므로 음수면 0을 만들어줌
			int nb = max(0, b - dmgs[i][1]);
			int nc = max(0, c - dmgs[i][2]);
			if (visited[na][nb][nc])
				continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({na, nb, nc});
		}
	}
	return (visited[0][0][0] - 1);
}

int main()
{
	int N;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> scv[i];
	}
	cout << solve(scv[0], scv[1], scv[2]) << "\n";

	return 0;
}