// https://www.acmicpc.net/problem/13913
/*
문제:
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 N(0 <= N <= 100000)에 있고,
동생은 점 K(0 <= K <= 100000)에 있다
수빈이는 걷거나 순간이동을 할 수 있다.
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하ㅔ 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다
수빈이와 동생의 위치가 주어졌을 때,
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오

입력:
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다

출력:
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
둘째 줄에 어떻게 이동해야 하는 지 공백으로 구분해 출력한다.

ex:
입력
5 17

출력
4
5 10 9 18 17

1285 숨바꼭질 BFS + trace
prev[next] = here
1 -> 4 -> 9 -> 11
prev[4] = 1
prev[9] = 4
prev[11] = 9
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int subin, bro;

	cin >> subin >> bro;
	vector<int> visited(200001, 0);
	vector<int> prev(200001, 0);
	vector<int> root;
	queue<int> q;

	visited[subin] = 1;
	q.push(subin);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
	
		if (now == bro) // 동생을 찾으면 바로 종료
			break;

		for (int next : {now+1, now-1, now*2})
		{
			if (next < 0 || next > 200000)
				continue;
			if (visited[next])
				continue;
			visited[next] = visited[now] + 1;
			prev[next] = now; // 다음 위치로 이동하기 직전의 위치를 기록
			q.push(next);
		}
	}
	// 동생으로부터 수빈이가 아닐때까지 경로에 넣기
	// ex)
	// 5 4 8 16 17 
	// 17 -> 16 -> 8 -> 4
	for (int i = bro; i != subin; i = prev[i])
		root.push_back(i);
	// 시작위치를 넣고 reverse 하려면 푸쉬백 한 후 reverse
	// root.push_back(subin); 

	// subin -> 동생으로 가는 경로기 때문에 reverse로 뒤집기
	reverse(root.begin(), root.end());

	// 시작 위치는 포함되지 않았으므로 맨 앞에 시작 위치 추가
	root.insert(root.begin(), subin);

	cout << visited[bro] - 1 << "\n";
	for (int i : root)
		cout << i << " ";
	cout << "\n";
	return 0;
}
