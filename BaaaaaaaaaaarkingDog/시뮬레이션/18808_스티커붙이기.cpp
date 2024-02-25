// https://www.acmicpc.net/problem/18808

/*
n, m 노트북 크기 
k 스티커 개수
r, c 스티커 크기
ret 노트북에 붙은 스티커 사이즈
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, k, r, c, ret;
vector<vector<int> > noteBook(41, vector<int>(41, 0));
vector<vector<int> > sticker(11, vector<int>(11, 0));

void countSticker()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (noteBook[i][j] == 1)
				ret++;
		}
	}
}

void rotate()
{
	vector<vector<int> > temp(r, vector<int>(c, 0));

	// 스티커 복사
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			temp[i][j] = sticker[i][j];
		}

	}

	// 시계 뱡향으로 회전
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			sticker[i][j] = temp[r-j-1][i];
		}
	}
  	swap(r, c); // 회전 시킨 후 스티커의 가로, 세로 크기 교환
}

void stick(int y, int x)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (sticker[i][j] == 1)
				noteBook[y+i][x+j] = 1;
		}
	}
}

bool isPossible(int y, int x)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			// 스티커를 붙일 자리에 이미 스티커가 있다면
			if (sticker[i][j] == 1 && noteBook[y+i][x+j] == 1)
				return false;
		}
	}
	return true;
}

void simulation()
{
	// 4 방향으로 돌리면서 스티커를 붙일 수 있다면 붙이기
		for (int rot = 0; rot < 4; ++rot)
		{
			// 스티커가 노트북에 붙일 수 있는 사이즈인지 확인한다
			for (int i = 0; i <= n-r; ++i)
			{
				for (int j = 0; j <= m-c; ++j)
				{
					// 올바른 사이즈의 스티커면 노트북에 붙일 수 있는지 확인 한다
					if (isPossible(i, j))
					{
						stick(i, j); // 붙인다
						return;
					}
				}
			}
			// 못붙였으면 시계방향으로 90도 회전
			rotate();
		}
}

int main()
{
	cin >> n >> m >> k;

	// 스티커의 개수만큼 반복
	while (k--)
	{
		cin >> r >> c;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				cin >> sticker[i][j];

		simulation();

		// 사용한 스티커 초기화
		for (int i = 0; i < sticker.size(); ++i)
			fill(sticker[i].begin(), sticker[i].end(), 0);

	}
	countSticker();

	cout << ret << "\n";
	return 0;
}