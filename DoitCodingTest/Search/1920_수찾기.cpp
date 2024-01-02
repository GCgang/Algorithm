// https://www.acmicpc.net/problem/1920
/*
문제:
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력:
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 
다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다.
다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 
다음 줄에는 M개의 수들이 주어지는데,
이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력:
M개의 줄에 답을 출력한다. 
존재하면 1을, 존재하지 않으면 0을 출력한다.

ex:
입력		    	출력
5				   1
4 1 5 2 3		   1
5				   0
1 3 7 9 5		   0
				   1
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

	
	int N, M;
	cin >> N;
	
	vector<int> A(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		bool find = false;
		int target;
		cin >> target;
		// 이진 탐색 시작
		int start = 0;
		int end = A.size() - 1;

		while (start <= end)
		{
			int midi = (start + end) / 2;
			int midV = A[midi];

			if (midV > target)
				end = midi - 1;
			else if (midV < target)
				start = midi + 1;
			else 
			{
				find = true;
				break ;
			}
		}
		if (find)
			cout << 1 << "\n";
		else 
			cout << 0 << "\n";
	}
	return 0;
}