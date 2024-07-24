// https://www.acmicpc.net/problem/11004
/*
문제:
수 N개 A1, A2, ..., AN이 주어진다. A를 오름차순 정렬했을 때, 앞에서부터 K번째 있는 수를 구하는 프로그램을 작성

입력:
1번째 줄에 N(1 ≤ N ≤ 5,000,000)과 K (1 ≤ K ≤ N)이 주어진다.
2번째 줄에는 A1, A2, ..., AN이 주어진다. (-10^9 ≤ Ai ≤ 10^9)

출력:
A를 정렬했을 때, 앞에서부터 K번째 있는 수를 출력한다.

ex:
입력			출력
5 2			   2
4 1 2 3 5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;


	vector<int> numArray(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> numArray[i];
	}

	sort(numArray.begin(), numArray.end());

	cout << numArray[K-1] << "\n";

	return 0;
}