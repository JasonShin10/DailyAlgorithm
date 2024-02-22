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
const int INF = 987654321;
char arr[1004][1004] = {};
bool visited[1004][1004] = {};
int fireCheck[1004][1004] = {};
int hoonCheck[1004][1004] = {};
int ret;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int R, C;
pair<int, int> jp;

queue<pair<int, int>> mq;

void BFS()
{
	while (!mq.empty())
	{
		int x = mq.front().first;
		int y = mq.front().second;

		mq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C && visited[nx][ny] == false && arr[nx][ny] == '.')
			{
				mq.push({ nx,ny });
				fireCheck[nx][ny] = fireCheck[x][y] + 1;
				visited[nx][ny] = true;
			}
		}
	}


	mq.push({ jp.first,jp.second });
	while (!mq.empty())
	{
		int x = mq.front().first;
		int y = mq.front().second;
		mq.pop();

		if (x == R - 1 || x == 0 || y == C - 1 || y == 0)
		{
			ret = hoonCheck[x][y];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C)
			{
				if (fireCheck[nx][ny] > hoonCheck[x][y] + 1)
				{
					if (hoonCheck[nx][ny] == 0 && arr[nx][ny] != '#')
					{
						hoonCheck[nx][ny] = hoonCheck[x][y] + 1;
						mq.push({ nx,ny });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	fill(&fireCheck[0][0], &fireCheck[0][0] + 1004 * 1004, INF);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'J')
			{
				jp = { i,j };
				hoonCheck[i][j] = 1;
			}
			else if (arr[i][j] == 'F')
			{
				fireCheck[i][j] = 1;
				visited[i][j] = true;
				mq.push({ i,j });
			}
		}
	}

	BFS();
	if (ret != 0)
	{
		cout << ret << '\n';
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
}
