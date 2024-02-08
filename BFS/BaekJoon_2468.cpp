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

vector<vector<int>> arr;
vector<vector<int>> oriArr;
bool visited[101][101] = {};

// 위 , 아래, 오른쪽, 위;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<pair<int, int>> mq;
int N;
int cnt=0;
void BFS(int a, int b)
{
	mq.push({ a,b });
	visited[a][b] = true;

	while (!mq.empty())
	{
		int x = mq.front().first;
		int y = mq.front().second;
		mq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N && visited[nx][ny] == false)
			{
				if (arr[nx][ny] != -1)
				{
					mq.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
	}

}
int mx = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	oriArr.resize(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> oriArr[i][j];
		}
	}

	for (int k = 0; k < 101; k++)
	{
		arr = oriArr;
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] <= k)
				{
					arr[i][j] = -1;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] != -1 && visited[i][j] == false)
				{
				BFS(i, j);
				cnt++;
				}
			}
		}
		if (mx < cnt)
		{
			mx = cnt;
		}
	}
	cout << mx;
}
