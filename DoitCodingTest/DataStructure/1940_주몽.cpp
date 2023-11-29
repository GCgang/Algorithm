// https://www.acmicpc.net/problem/1940
/*
문제:
주몽은 철기군을 양성하기 위한 프로젝트에 나섰다.
야철대장은 주몽의 명렁에 따라 연구에 착수하던 중 갑옷을 만든느 재료들은 각각 고유한 번호가 있고,
갑옷은 2개의 재료로 만드는 데 2가지 재료의 고유한 번호를 합쳐
M(1 <= M <= 10,000,000)이 되면 갑옷이 된다는 사실을 발견했다.
N(1 <= N <= 15,000)개의 재료와 M이 주어졌을 때 몇개의 갑옷을 만들 수 있는지 구하는 프로그램을 작성하시오.

입력:
1번째 줄에 재료의 개수 N(1 <= N <= 15,000)
2번째 줄에 갑옷을 만드는 데 필요한 수 M(1 <= M <= 10,000,000)이 주어진다.
3번째 줄에는 N개의 재료들이 가진 고유한 번호들이 공백을 사이에 두고 주어진다.
고유한 번호는 100,000보다 작거나 같은 자연수다

ex:
입력                                출력
6           재료의 개수                2
9           갑옷이 완성되는 번호의 합
2 7 4 1 5 3 재료들

투포인터 이동 원칙:
A[i] + A[j] > M: j--; 번호의 합이 M보다 크므로 큰 번호 index를 내린다
A[i] + A[j] < M: i++; 번호의 합이 M보다 작으므로 작은 번호 index를 올린다
A[i] + A[j] == M: i++; j--; count++ 양쪽 포인터를 모두 이동시키고 count를 증가시킨다
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 투포인터 풀이
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int materialCount, armor;

    cin >> materialCount >> armor;

    vector<int> materials(materialCount, 0);

    for (int i = 0; i < materialCount; i++)
    {
        cin >> materials[i];
    }

    sort(materials.begin(), materials.end());

    int i = 0;
    int j = materialCount - 1;
    int result = 0;

    // 투 포인터 이동 원칙에 따라 포인터를 이동하여 처리
    while (i < j)
    {
        if (materials[i] + materials[j] > armor)
        {
            j--;
        }
        else if (materials[i] + materials[j] < armor)
        {
            i++;
        }
        else if (materials[i] + materials[j] == armor)
        {
            i++;
            j--;
            result++;
        }
    }
    cout << result << "\n";

    return 0;
}

/*
반복문 풀이

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int materialCount, armor, result = 0;

    cin >> materialCount >> armor;

    vector<int> materials(materialCount, 0);

    for (int i = 0; i < materialCount; i++)
    {
        cin >> materials[i];
    }

    for (int i = 0; i < materialCount - 1; i++)
    {
        for (int j = i; j < materialCount - 1; j++)
        {
            if (materials[i] + materials[j + 1] == armor)
            {
                result++;
            }
        }
    }

    cout << result << "\n";

    return 0;
}
*/
