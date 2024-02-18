// https://www.acmicpc.net/problem/10866
/*
문제:
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력:
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력:
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

ex:
입력
15
push_back 1
push_front 2
front
back
size
empty
pop_front
pop_back
pop_front
size
empty
pop_back
push_front 3
empty
front

출력
2
1
2
0
2
1
-1
0
1
-1
0
3
*/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N, num;
string order;
deque<int> dq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--)
	{
		cin >> order;
		if (order == "push_front")
		{
			cin >> num;
			dq.push_front(num);	
		}
		else if (order == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if (order == "pop_front")
		{
			if (!dq.empty()) 
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (order == "pop_back")
		{
			if (!dq.empty()) 
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if (order == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (order == "empty")
		{
			cout << (int)dq.empty() << "\n";
		}
		else if (order == "front")
		{
			dq.empty() ? cout << -1 << "\n" : cout << dq.front() << "\n";
		}
		else if (order == "back")
		{
			dq.empty() ? cout << -1 << "\n" : cout << dq.back() << "\n";
		}
	}
	return 0;
}
