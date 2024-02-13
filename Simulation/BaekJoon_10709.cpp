#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <cstring> 

using namespace std;

char arr[100][100] = {};

int nArr[100][100] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int H, W;
	cin >> H >> W;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			nArr[i][j] = -1;
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (arr[i][j] == 'c')
			{
				nArr[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (nArr[i][j] == 0)
			{
				int d = j + 1;
				int cnt = 1;
				while (d < W)
				{
					if (nArr[i][d] == 0)
					{
						break;
					}
					nArr[i][d] = cnt;
					d++;
					cnt++;
				}
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << nArr[i][j] << " ";
		}
		cout << '\n';
	}
}
