#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <cstring>
#include <stack>

using namespace std;

char arr[51][51] = {};
int nArr[51][51] = {};

bool visited[51][51] = {};

queue<pair<int, int>> mq;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, M;
int mx = -1e9;
int ans = -1e9;
void BFS(int x, int y)
{
	mq.push({ x,y });
	nArr[x][y] =0;
	visited[x][y] = true;
	while (!mq.empty())
	{
		int x = mq.front().first;
		int y = mq.front().second;
		mq.pop();

		if (mx < nArr[x][y])
		{
			mx = nArr[x][y];
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false && arr[nx][ny] == 'L')
			{
				mq.push({ nx, ny });
				nArr[nx][ny] = nArr[x][y] + 1;
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'L')
			{
				BFS(i, j);
				if (ans < mx)
				{
					ans = mx;
				}
				memset(visited, 0, sizeof(visited));
			}
		}
	}

	cout << ans;
}
