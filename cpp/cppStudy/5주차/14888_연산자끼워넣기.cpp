// https://www.acmicpc.net/problem/14888


#include <iostream>
#include <algorithm>
using namespace std;

int N, add, sub, mul, divi;
int maxRet = -1000000001;
int minRet = 1000000001;
int A[12];

void go(int index, int cur, int add, int sub, int mul, int divi)
{
    if (index == N -1)
    {
        maxRet = max(maxRet, cur);
        minRet = min(minRet, cur);
        return ;
    }

    if (add)
        go(index + 1, cur + A[index + 1], add - 1, sub, mul, divi);
    if (sub)
        go(index + 1, cur - A[index + 1], add, sub - 1, mul, divi);
    if (mul)
        go(index + 1, cur * A[index + 1], add, sub, mul - 1, divi);
    if (divi)
        go(index + 1, cur / A[index + 1], add, sub, mul, divi - 1);
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    cin >> add >> sub >> mul >> divi;
    
    go(0, A[0], add, sub, mul, divi);

    cout << maxRet << "\n";
    cout << minRet << "\n";

    return 0;
}