// https://www.acmicpc.net/problem/2852
/*
문제:
동혁이는 골이 들어갈 때 마다 골이 들어간 시간과 팀을 적는 취미가 있다.
농구 경기는 정확히 48분 진행된다.
각 팀이 몇 분동안 이기고 있었는지 출력하는 프로그램을 작성하시오

입력:
첫쨰 줄에 골이 들어간 횟수(N (1 <= N <= 100)이 주어진다
둘째 줄부터 N개의 줄에 득점 정보가 주어진다.
득정 정보는 득점한 팀의 번호와 득점한 시간으로 이루어져 있다.
팀 번호는 1 또는 2이다. 득점한 시간은 MM:SS(분:초) 형식이며, 분과 초가 한자리 일 경우 첫째자리가 0이다.
분은 0보다 크거나 같고, 47보다 작거나 같으며, 초는 0보다 크거나 같고, 59보다 작거나 같다. 득점 시간이 겹치는 경우는 없다.

출력:
첫째 줄에 1번 팀이 이기고 있던 시간,
둘쨰 줄에 2번 팀이 이기고 있던 시간을 출력한다.
시간은 입력과 같은 형식(MM:SS)으로 출력한다.

ex:
입력         출력
1           28:00
1 20:00     00:00

3           20:00
1 01:10     16:30
2 21:10
2 31:30


*/

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int N, team, A, B, asum, bsum;
string timeS, prevS; 

// 정수 형식의 시간(초)을 MM:SS 형식의 문자열로 변환하는 함수
string print(int a){ 
    // 분을 문자열로 변환, 항상 두 자릿수를 유지하기 위해 앞에 "00"을 붙임
    string d = "00" + to_string(a / 60); 
    // 초를 문자열로 변환, 항상 두 자릿수를 유지하기 위해 앞에 "00"을 붙임
    string e = "00" + to_string(a % 60); 
    // 두 문자열의 끝에서 두 자리를 추출하여 MM:SS 형식으로 반환
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}

// 문자열 형식의 시간(MM:SS)을 초 단위의 정수로 변환하는 함수
int changeToInt(string a){
    // 분과 초를 분리하여 정수로 변환 후, 총 초로 계산
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

// 현재 시간과 이전 시간의 차이를 주어진 합계에 더하는 함수
void go(int &sum, string timeS){ 
    // 현재 시간과 이전 시간의 차이를 계산하여 sum에 더함
    sum += (changeToInt(timeS) - changeToInt(prevS)); 
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> team >> timeS; // 득점한 팀 번호와 시간 입력
        // 팀 A가 이기고 있다면 asum에 시간 차이 추가
        if(A > B) go(asum, timeS);
        // 팀 B가 이기고 있다면 bsum에 시간 차이 추가
        else if(B > A) go(bsum, timeS);
        // 득점한 팀의 점수를 증가
        team == 1 ? A++ : B++;
        prevS = timeS; // 현재 시간을 이전 시간으로 업데이트
    } 
    // 경기 종료 시점에서 이기고 있는 팀의 시간 추가
    if(A > B)
        go(asum, "48:00");
    else if(B > A)
        go(bsum, "48:00"); 
    // 최종 시간 출력
    cout << print(asum) << "\n"; 
    cout << print(bsum) << "\n";

    return 0;
}