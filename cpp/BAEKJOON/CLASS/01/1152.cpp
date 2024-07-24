// https://www.acmicpc.net/problem/1152

#include <iostream>
#include <sstream>
using namespace std;

int main()
{
  string input;
  getline(cin, input);
  istringstream iss(input);
  string word;
  int cnt = 0;

  while (iss >> word) {
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}