#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int A[501][501] = {};
bool visited[501][501] = {};
// 위, 아래, 오른, 왼쪽

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

queue<pair<int, int>> mq;

int N, M;
int bfs()
{
	int size = 0;
	while (!mq.empty())
	{
		int x = mq.front().first;
		int y = mq.front().second;
		mq.pop();
		size++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && A[nx][ny] == 1 && !visited[nx][ny])
			{
				visited[nx][ny] = true;
				mq.push({ nx,ny });
			}
		}
	}
	return size;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}

	int cnt = 0;
	int mx = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = true;
				mq.push({ i,j });
				cnt++;
				mx = max(mx,bfs());
			}
		}
	}

	cout << cnt << endl;
	cout << mx << endl;
}
