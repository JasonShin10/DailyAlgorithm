#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n, x, y, d, g,ret;
int mp[104][104];
// 오른, 위, 왼, 아래
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
vector<int> dir;

void makeDragon()
{
	int size = dir.size();
	for (int i = size - 1; i >= 0; i--)
	{
		d = (dir[i]+1) % 4;
		x = x + dx[d];
		y = y + dy[d];
		mp[x][y] =1;
		dir.push_back(d);
	}
}

void countSquare()
{
	for(int i =0; i<101; i++)
		for (int j = 0; j < 101; j++)
		{
			if (mp[i][j] == 1 && mp[i][j + 1] == 1 && mp[i + 1][j] == 1 && mp[i + 1][j + 1] == 1)
			{
				ret++;
			}
		}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> y >> x >> d >> g;
		
		mp[x][y] = 1;
		x += dx[d];
		y += dy[d];
		mp[x][y] = 1;
		dir.push_back(d);
		while (g--)
		{
			makeDragon();
		}
		dir.clear();
	}
	countSquare();
	cout << ret;
}
