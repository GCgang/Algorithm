// https://www.acmicpc.net/problem/1911
/*
문제:
어젯밥 겨울 캠프 장소에서 월드 본원까지 이어지는, 
흙으로 된 비밀길 위에 폭우가 내려서 N(1 <= N <= 10,000)개의 물웅덩이가 생겼다.
월드학원은 물웅덩이를 덮을 수 있는 길이가 L(1 <= L <= 1,000,000)인 널빤지들을 충분히 가지고 있어서,
이들로 다리를 만들어 물웅덩이들을 모두 덮으려고 한다.
물웅덩이들의 위치와 크기에 대한 정보가 주어질 때,
모든 물웅덩이들을 덮기 위해 필요한 널빤지들의 최소 개수를 구하여라

입력:
첫째 줄에 두 정수 N과 L이 들어온다
둘째 줄부터 N+1 번째 줄에 총 N개의 줄에 각각의 웅덩이들의 정보가 주어진다.
웅덩이의 정보는 웅덩이의 시작 위치와 끝 위치로 이루어진다.
각 위치는 0 이상, 1,000,000,000 이하의 정수이다.
입력으로 주어지는 웅덩이는 겹치지 않는다

출력:
첫째 줄에 모든 물웅덩이들을 덮기 위해 필요한 널빤지들의 최소 개수를 출력한다

ex:
입력
3 3
1 6
13 17
8 12

출력:
5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, L, idx = 0, ret = 0, cnt = 0;
int main()
{
	cin >> N >> L;


	vector<pair<int, int > > v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end());

	for (int i = 0; i < N; ++i)
	{
		// 물웅덩이가 이미 덮여있으면 넘어감
		if (v[i].second <= idx)
			continue;
		// 널빤지의 가장 끝값보다 물웅덩이의 가장 앞쪽값이 크면 널빤지를 깔아야  함(웅덩이 시작 전인 경우)
		else if (v[i].first > idx)
		{
			cnt = (v[i].second - v[i].first) / L + ((v[i].second - v[i].first) % L ? 1 : 0);
			idx = v[i].first + cnt * L;
		}
		// 현재 웅덩이가 덮인 구간에 일부 포함되어 있다면
		else 
		{
			cnt = (v[i].second - idx) / L + ((v[i].second - idx) % L ? 1 : 0);
			idx += cnt * L;
		}
		ret += cnt;
	}

	cout << ret << "\n";
	return 0;
}