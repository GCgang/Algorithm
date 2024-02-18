// https://www.acmicpc.net/problem/1021
/*
문제:
지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다.
지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.
지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.
첫 번째 원소를 뽑아낸다. 이 연산을 수행하면,
	원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다.이 연산을 수행하면,
	a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면,
	a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다.
그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

입력:
첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다.
N은 50보다 작거나 같은 자연수이고,
M은 N보다 자거나 같은 자연수이다.
들째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다.
위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

출력:
첫째 줄에 문제의 정답을 출력한다

ex:
입력
10 3
1 2 3

출력
0
*/

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, M, pos, idx, ret;
deque<int> dq;

int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		dq.push_back(i);
	
	while (M--)
	{
		cin >> pos;
		idx = find(dq.begin(), dq.end(), pos) - dq.begin(); // 찾은 인덱스 반환
		while (dq.front() != pos) // 큐의 맨앞이 idx와 같을 때까지 반복
		{
			if (idx < dq.size() - idx) // idx가 앞쪽에 가깝다는 의미 (dq.size() - idx) => idx가 끝부터 얼마나 떨어져 있는지를 구함
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ret++;
		}
		dq.pop_front(); // 찾았으니 pop
	}
	cout << ret << "\n";
	return 0;
}