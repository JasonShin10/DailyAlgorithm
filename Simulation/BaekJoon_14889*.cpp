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

int arr[24][24] = {};
int N;
bool selected[24] = {};
int mn = 1e9;

void counting()
{
	int s = 0;
	int l = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (selected[i] && selected[j])
			{
				s += arr[i][j];
			}
			if (!selected[i] && !selected[j])
			{
				l += arr[i][j];
			}
		}
	}

	int ret = abs(s - l);
	if (ret < mn)
	{
		mn = ret;
	}
}
void DFS(int count, int idx)
{
	if (count == N / 2)
	{
		counting();
	}

	for (int i = idx; i < N; i++)
	{
		selected[i] = true;
		DFS(count + 1, i + 1);
		selected[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	DFS(0, 0);
	cout << mn;
}
