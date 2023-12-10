// https://www.acmicpc.net/problem/2164
/*
문제:
N장의 카드는 각각 차례로 1에서 N까지의 번호가 붙어 있다
1번 카드가 가장 위, N번 카드가 가장 아래인 상태로 놓여 있다.
이제 다음과 같은 동작을 카드가 1장 남을 때까지 반복한다
먼저 가장 위에 있는 카드를 바닥에 버린다. 그 다음 가장 위에 있는 카드를 가장 아래에 있는 카드 밑으로 옮긴다
예를 들어 N = 4일 때를 생각해보자. 카드는 가장 위에서부터 1, 2, 3, 4,의 순서대로 놓여 있다.
1을 버리면 2, 3, 4가 남는다. 여기서 2를 가장 아래로 옮기면 순서가 3, 4, 2가 된다.
3을 버리면 4, 2가 남고, 4를 밑으로 옮기면 순서가 2, 4가 된다.
마지막으로 2를 버리면 카드 4가 남는다.
N이 주어졌을 때 가장 마지막에 남는 카드를 구하는 프로그램을 작성하시오.

입력:
1번째 줄에 정수 N(1 <= N <= 500,000)이 주어진다.

출력:
1번째 줄에 남는 카드의 번호를 출력한다.

ex:
입력                출력
6   // 카드의 개수     4
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> card;

    for (int i = 1; i <= N; ++i)
    {
        card.push(i);
    }
    // 카드 게임 규칙 적용 버리기(pop) 버린 이후 카드 맨 밑으로 이동(pop 한 값 push)
    for (int i = card.size() - 1; i > 0; --i)
    {
        card.pop();
        int num = card.front();
        card.pop();
        card.push(num);
    }
    cout << card.front();
    return (0);
}