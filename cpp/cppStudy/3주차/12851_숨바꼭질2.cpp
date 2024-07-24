// https://www.acmicpc.net/problem/12851
/*
문제:
수빈이는 동생과 숨바꼭질을 하고 있다.
수빈이는 현재 점 subin(0 <= subin <= 100,000)에 있고,
동생은 점 bro(0 <= bro <= 100,000)에 있다.
수빈이는 걷거나 순간이동을 할 수 있다.
만약, 수빈이의 위치가 X일 때 걷는다면 1초후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 그리고,
가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램을 작성하시오

입력:
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력:
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다
둘째 줄에는 가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수를 출력한다

ex:
입력
5, 17
 
출력
4
2
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{

	int subin, bro;

	cin >> subin >> bro;

	vector<int> visited(100001, 0);
	vector<int> cnt(100001, 0);
	queue<int>q;

	if (subin == bro)
	{
		cout << 0 << "\n" << 1 << "\n";
		return 0;
	}

	visited[subin] = 1;
	cnt[subin] = 1;
	q.push(subin);

	while (!q.empty())
	{
		int now = q.front();
		vector<int> move;
		move.push_back(now+1);
		move.push_back(now-1);
		move.push_back(now*2);
		q.pop();
		// for(int next : {now+1, now-1, now*2})
		for(int next : move)
		{
			// cout << "현재 위치 : " << now << "\n";
			// cout << "이동할 수 있는 위치 : " << move[0] << ", " << move[1] << ", " << move[2] << "\n";
			// cout << "다음 위치 : " << next << "\n";
			if (next < 0 || next > 100000)
				continue;
			if (!visited[next])
			{
				q.push(next);
				visited[next] = visited[now] + 1;
				cnt[next] += cnt[now];
			}
			else if (visited[next] == visited[now] + 1)
				cnt[next] += cnt[now];
			// cout << "방문 여부 : " << visited[next] << "\n";
			// cout << "방법의 수 : " << cnt[next] << "\n";
		}
	}
	cout << visited[bro] - 1 << "\n";
	cout << cnt[bro] << "\n";
	return 0;
}