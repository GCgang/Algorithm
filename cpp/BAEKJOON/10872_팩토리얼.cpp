// https://www.acmicpc.net/problem/10872
/*
문제:
0보다 크거나 같은 정수 N이 주어진다.
이때, N!을 출력하는 프로그램을 작성하시오

입력:
첫째 줄에 정수 N(0 <= N <= 12)이 주어진다

출력:
첫째 줄에 N!을 출력한다

ex:
입력
10      3628800
*/
#include <iostream>
int factorial(int n);
static int N;

/*
함수정의
n을 받아서 n!를 반환하는 함수
f(4) = 4! = 24
f(5) = 5! = 120

기저조건
0! = 1 (정의가 그렇다)
if (n == 0)
    return 1;

재귀적 식
n! = n x (n - 1);
*/
int main()
{   
    std::cin >> N;
    
    std::cout << factorial(N) << "\n";

    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;

    return (n * factorial(n - 1));
}