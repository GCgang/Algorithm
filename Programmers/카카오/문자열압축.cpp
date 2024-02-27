// https://school.programmers.co.kr/learn/courses/30/lessons/60057

#include <iostream>
#include <string>
using namespace std;

int compress(const string &s, int len) {
    string comp = ""; // 압축된 문자열을 저장
    string prev = s.substr(0, len); // 첫 번째 부분 문자열
    int count = 1; // 현재 문자열 반복 횟수
    
    // 문자열을 압축 단위만큼 잘라가며 반복
    for (int i = len; i < s.length(); i += len)
    {
        string sub = s.substr(i, len); // 현재 압축 단위에서 부분 문자열 추출
        if (prev == sub) // 이전 부분 문자열과 현재 부분 문자열이 같으면 카운트 증가
        {
            count++;
        }
        else // 다르면 지금까지 결과를 comp에 추가
        {
            if (count > 1) // count가 1보다 크면, 숫자를 문자열로 변환하여 붙임
                comp += to_string(count) + prev;
            else // count가 1보다 작으면, 숫자를 붙이지 않고 prev만 추가
                comp += prev;
            // 현재 부분 문자열을 prev로 설정 후 카운트 1로 초기화
            prev = sub;
            count = 1;
        }
    }
    // 마지막에 남은 부분도 처리
    if (count > 1)
        comp += to_string(count) + prev;
    else
        comp += prev;
    return comp.length();
}

int solution(string s)
{
    int answer = s.length(); // 최소 길이를 초기 문자열 길이로 설정
    for (int len = 1; len <= s.length() / 2; ++len) // 최대 길이 /2 까지만 비교
    {
        answer = min(answer, compress(s, len));
    }
    return answer;
}
