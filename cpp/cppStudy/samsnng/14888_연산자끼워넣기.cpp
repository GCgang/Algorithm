#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, minRet = INT_MAX, maxRet = INT_MIN;
vector<int> nums;
int oper[4];
vector<int> operType;


// 0 1 2 3
// + - * /


int main()
{
    cin >> N;

    nums.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> oper[i];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < oper[i]; ++j) {
            operType.push_back(i);
        }
    }

    sort(operType.begin(), operType.end());

    do
    {
        int ret = nums[0];
        for (int i = 0; i < N - 1; ++i)
        {
            if (operType[i] == 0)
                ret += nums[i + 1];
            else if (operType[i] == 1)
                ret -= nums[i + 1];
            else if (operType[i] == 2)
                ret *= nums[i + 1];
            else
                ret /= nums[i + 1];
        }
        minRet = min(ret, minRet);
        maxRet = max(ret, maxRet);
    } while (next_permutation(operType.begin(), operType.end()));

    cout << maxRet << "\n";
    cout << minRet << "\n";
    return 0;
}