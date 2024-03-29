// https://www.acmicpc.net/problem/13458

/*
문제:
총 N개의 시험장이 있고, 각각의 시험장마다 응시자들이 있다.
i번 시험장에 있는 응시자의 수는 Ai명이다.
감독관은 총감독관과 부감독관으로 두 종류가 있다.
총감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 B명이고,
부감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 C명이다.
각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.
각 시험장마다 응시생들을 모두 감시해야 한다.
이때, 필요한 감독관 수의 최솟값을 구하는 프로그램을 작성하시오.

입력:
첫째 줄에 시험장의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 각 시험장에 있는 응시자의 수 Ai (1 ≤ Ai ≤ 1,000,000)가 주어진다.
셋째 줄에는 B와 C가 주어진다. (1 ≤ B, C ≤ 1,000,000)

출력:
각 시험장마다 응시생을 모두 감독하기 위해 필요한 감독관의 최소 수를 출력한다.

ex:
입력
3
3 4 5
2 2

출력
7

입력
5
1000000 1000000 1000000 1000000 1000000
5 7

출력
714290
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B, C;
long long ret;
vector<int> A;

int main()
{
	cin >> N;

	A.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	cin >> B >> C;

	for (int i = 0; i < N; ++i)
	{ 
		ret++; // 총감독관 1명
		A[i] -= B; // 총감독관이 감시할 수 있는 응시자 수 제외
		
		if (A[i] > 0)  // 남은 응시자가 있다면
		{
			ret += A[i] / C; // 필요한 부감독관 수 계산
			if (A[i] % C) // 나머지가 있다면 부 감독관 한 명 추가
				ret++;
		}
	}

	cout << ret << "\n";
	return 0;
}