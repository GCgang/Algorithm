// https://www.acmicpc.net/problem/1427
/*
문제:
배열을 정렬하는 것은 쉽다.
수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자

입력:
1번째 줄에ㅔ 정렬하려고 하는 수 N이 주어진다.
N은 1,000,000,000보다 작거나 같은 자연수이다

출력:
1번째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다

ex)
입력	   출력
2143	4321

61423	64321
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> numArray;
	while (N)
	{
		numArray.push_back(N % 10);
		N /= 10;
	}

	sort(numArray.begin(), numArray.end());

	for (int i = numArray.size() - 1; i >= 0 ; --i)
	{
		cout << numArray[i];
	}	
	return (0);
}