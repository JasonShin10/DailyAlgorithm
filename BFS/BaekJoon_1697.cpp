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

queue<pair<int, int>> mq;
vector<bool> visited;
int mn = 1e9;
int N, K;


void BFS(int n, int m)
{
	mq.push({ n,m });
	visited[n] = true;

	while (!mq.empty())
	{
		int x = mq.front().first;
		int cnt = mq.front().second;

		if (x == K)
		{
			if (mn > cnt)
			{
				mn = cnt;
			}
			return;
		}
		mq.pop();

		for (int i = 0; i < 3; i++)
		{
			int nx = 0;
			if (i == 0)
			{
				nx = x - 1;
				if (nx >= 0 && visited[nx] == false)
				{
					mq.push({ nx, cnt + 1 });
					visited[nx] = true;
				}
			}
			else if (i == 1)
			{
				nx = x + 1;
				if (nx < 100001 && visited[nx] == false)
				{
					mq.push({ nx, cnt + 1 });
					visited[nx] = true;
				}
			}
			else if (i == 2)
			{
				nx = 2 * x;
				if (nx < 100001 && visited[nx] == false)
				{
					mq.push({ nx, cnt + 1 });
					visited[nx] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	visited.resize(100001);

	cin >> N >> K;

	BFS(N, 0);
	cout << mn;
}
