#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int index = 0; index < commands.size(); ++index)
    {
        int i, j, k;
        i = commands[index][0];
        j = commands[index][1];
        k = commands[index][2];

        // i부터 j까지 벡터를 복사
        vector<int> subArray(array.begin() + i - 1, array.begin() + j);
        
        // 복사된 벡터 정렬
        sort(subArray.begin(), subArray.end());
        
        // k번째 숫자 추가
        answer.push_back(subArray[k - 1]);
    }
    return answer;
}

// int main() {
//     vector<int> array = {1, 5, 2, 6, 3, 7, 4};
//     vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
//     vector<int> result = solution(array, commands);

//     for (int num : result) {
//         cout << num << " ";
//     }

//     return 0;
// }