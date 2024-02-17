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
bool visited[51][51] = {};
int path[51][51] = {};
queue<pair<int, int>> mq;
int N, M;
int mx = -1e9;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans = -1e9;
// 처음 지역부터 목표 지역까지 몇번 걸리는지 
void BFS(int x, int y)
{
	mq.push({ x,y });
	visited[x][y] = true;
	while (!mq.empty())
	{
		int x = mq.front().first;
		int y = mq.front().second;

		mq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 'L' && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				path[nx][ny] = path[x][y] + 1;
				mq.push({ nx, ny });
				if (mx < path[nx][ny])
				{
					mx = path[nx][ny];
				}
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
				if (mx > ans)
				{
					ans = mx;
				}
				memset(visited, 0, sizeof(visited));
				memset(path, 0, sizeof(path));
			}
		}
	}

	cout << ans;

}
