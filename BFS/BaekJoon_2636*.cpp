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

int arr[101][101];

queue<pair<int, int>> mq;
// 위, 아래, 왼 오
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool flag;
int N, M;

int timeCnt = 0;
int totalCheezeCnt = 0;
// 4방향 검사 1이면 큐에 넣는다.
// 바깥인지 안인지 확인해주어야 한다.
// 4방향 검사를 해서 0이면 밖이다.
// 0으로 바꿔주고 1이었는데 0으로 바꾼거라는 표시를 해준다.

int lastCheezeCnt = 0;
bool visited[101][101] = {};
void BFS(int x, int y)
{
	memset(visited, 0, sizeof(visited));
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
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false)
			{
				if (arr[nx][ny] == 1)
				{
					arr[nx][ny] = 0;
					totalCheezeCnt--;
				}
				else
				{
					mq.push({ nx, ny });
				}
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
			if (arr[i][j] == 1)
			{
				totalCheezeCnt++;
			}
		}
	}
	if (totalCheezeCnt == 0)
	{
		cout << 0 << '\n';
		cout << 0 << '\n';
		return 0;
	}

	while (totalCheezeCnt>0)
	{
		lastCheezeCnt = totalCheezeCnt;
		BFS(0, 0);
		timeCnt++;
	}
	cout << timeCnt << '\n';
	cout << lastCheezeCnt << '\n';

}
