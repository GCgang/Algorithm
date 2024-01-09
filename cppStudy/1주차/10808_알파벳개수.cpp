//https://www.acmicpc.net/problem/10808
/*
문제:
알파멧 소문자로만 이루어진 단어 S가 주어진다
각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오

입력:
첫째 줄에 단어 S가 주어진다.
단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다

출력:
단어에 포함되어 있는 a의 개수, b의 개수, ..., z의 개수를 공백으로 구분해서 출력한다

ex:
입력            출력
backjoon       1 1 0 0 1 0 0 0 0 1 1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0
*/

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main()
// {
//     string S;
//     string alpa = "abcdefghijklmnopqrstuvwxyz";
//     vector <int> arr(26, 0);

//     cin >> S;

//     for (int i = 0; i < S.size(); ++i)
//     {
//         int idx = alpa.find(S[i]);
//         if (idx != string::npos) // find 함수로 alpa 문자열에서 S의 글자를 돌면서 찾았다면 찾은 알파벳 개수 증가
//             arr[idx]++;
//     }
    
//     for (int i = 0; i < arr.size(); ++i)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

// 다른 풀이
#include <iostream>
#include <string>
using namespace std;  

string str; 
int cnt[26];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str; 
    for(char a : str)
        cnt[a - 'a']++;

	for(int i = 0; i < 26; i++)
        cout << cnt[i] << " ";

	return 0; 
}