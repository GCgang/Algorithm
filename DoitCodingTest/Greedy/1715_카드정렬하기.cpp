// https://www.acmicpc.net/problem/1715
/*
문제:
정렬될 각 묶음의 카드의 개수가 A, B일 때, 보통 두 묶음을 합쳐 1개로 만들려면 A + B 번 비교해야 한다
예를들어 20장의 카드묶음과 30장의 카드묶음을 합치려면 50번의 비교가 필요하다
매우 많은 숫자 카드 묶음이 있을 때 이들을 두 묶음씩 골라 서로 합쳐 나가면 고르는 순서에 따라 비교 횟수가 달라진다
예를들어 10장, 20장, 40장의 묶음이 있을떄, 이경우 (10 + 20) + (30 + 40) = 100 번의 비교가 필요하고
이경우 (10 + 40) + (50 + 20) = 120 번의 비교가 필요하여 덜 효율적이다
N개의 숫자 카드 묶음의 각각의 크기가 주어질 때 최소한 몇 번의 비교가 필요한지를 구하는 프로그램을 작성하시오

입력:
1번째 줄에 N이 주어진다(1 <= N <= 100,000)
그리고 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다
숫자 카드 묶음의 크기는 1,000보다 작거나 같은 양의 정수다

출력:
1번째 줄에 최소 비교 횟수를 출력한다

ex:
입력        출력
3          100
10
20
40

풀이
1 현재 카드의 개수가 가장 작은 묶음 2개를 선택해 합친다
2 합친 카드 묶음을 다시 전체 카드 묶음 속에 넣는다
3 과정 1 ~ 2를 카드 묶음이 1개만 남을 때까지 반복한다
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    priority_queue<int, vector<int>, greater<int> > pq; // 오른차순 정렬
    int data;

    for (int i = 0; i < N; ++i)
    {
        cin >> data;
        pq.push(data);
    }

    int data1 = 0, data2 = 0, sum = 0;

    while (pq.size() != 1)
    {
        data1 = pq.top();
        pq.pop();
        data2 = pq.top();
        pq.pop();
        sum += data1 + data2;
        pq.push(data1 + data2);
    }
    cout << sum << "\n";
    
}