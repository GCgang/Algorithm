// https://www.acmicpc.net/problem/16637
/*
문제:
길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+,-,x)로 이루어져 있다.
연산자 우선순위는 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다.
예를 들어, 3+8x7-9x2의 결과는 136이다
수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다.
단, 괄호 안에는 연산자가 하나만 들어 있어야 한다.
예를 들어 3+8x7-9x2에 괄호를 3+(8×7)-(9×2)와 같이 추가했으면, 식의 결과는 41이 된다. 
하지만, 중첩된 괄호는 사용할 수 없다.  즉, 3+((8×7)-9)×2, 3+((8×7)-(9×2))은 모두 괄호 안에 괄호가 있기 때문에, 올바른 식이 아니다.
수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오.
추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.

입력:
첫째 줄에 수식의 길이 N(1 <= N <= 19)가 주어진다.
둘째 줄에는 수식이 주어진다.
수식에 포함된 정수는 모두 0보다 크거나 같고, 9보다 작거나 같다.
문자열은 정수로 시작하고, 연산자와 정수가 번갈아가면서 나온다. 연산자는 +, -, *중 하나이다.
여기서 *는 곱하기 연산을 나타내는 x연산이다.
항상 올바른 수식만 주어지기 때문에, N은 홀수이다.

출력:
첫째 줄에 괄호를 적절히 추가해서 얻을 수 있는 결과의 최댓값을 출력한다.
정답은 2^31 보다 작고, -2^31보다 크다

ex:
입력					    출력
9					         136
3+8*7-9*2

5						     64
8*3+5	

19						     0
1*2+3*4*5-6*7*8*9*0

19						     426384
1*2+3*4*5-6*7*8*9*9
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> numArray;
vector<char> oper;
int ret = -987654321;

int cal(char op, int num1, int num2)
{
	if (op == '+')
		return (num1 + num2);
	if (op == '-')
		return (num1 - num2);
	if (op == '*')
		return (num1 * num2);
}

void go(int here, int num)
{
	// debug
	// cout << "here = " << here << " : " << "num = " << num  << " : " << "ret = " << ret <<  "\n";
	if (here == numArray.size() - 1)
	{
		ret = max(ret, num);
		return ;
	}

	go(here + 1, cal(oper[here], num, numArray[here + 1]));

	if (here + 2 <= numArray.size() - 1)
	{
		int temp = cal(oper[here + 1], numArray[here + 1], numArray[here + 2]);
		go(here + 2, cal(oper[here], num, temp));
	}
	return ;
}

int main()
{
	int N;
	string exepression;

	cin >> N;
	cin >> exepression;

	for (int i = 0; i < N; ++i)
	{
		if (i % 2 == 0)
			numArray.push_back(exepression[i] -'0');
		else
			oper.push_back(exepression[i]);
	}
	go(0, numArray[0]);

	cout << ret << "\n";
	return 0;
}