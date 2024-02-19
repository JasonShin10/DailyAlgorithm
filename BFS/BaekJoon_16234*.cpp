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

int arr[51][51] = {};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool visited[51][51] = {};


queue<pair<int, int>> mq;
vector<int> sumArr;
vector<pair<int, int>> updateArr;
int avg;
int N, L, R;
bool flag = true;
void BFS(int x, int y)
{
	mq.push({ x,y });
	visited[x][y] = true;
	updateArr.push_back({ x,y });
	int p = arr[x][y];
	sumArr.push_back(p);
	while (!mq.empty())
	{
		int x = mq.front().first;
		int y = mq.front().second;

		mq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] != true)
			{
				if (abs(arr[nx][ny] - arr[x][y]) >= L && abs(arr[nx][ny] - arr[x][y]) <= R)
				{
					sumArr.push_back(arr[nx][ny]);
					updateArr.push_back({ nx,ny });
					flag = true;
				mq.push({ nx,ny });
				visited[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	while (1)
	{
		flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] != true)
				{
					// 연합 찾음
					BFS(i, j);
					int sum = 0;
					avg = 0;

					// 영토 더함
					for (int k = 0; k < sumArr.size(); k++)
					{
						sum += sumArr[k];
					}
					avg = sum / sumArr.size();

					// 영토 업데이트
					for (int k = 0; k < updateArr.size(); k++)
					{
						int x = updateArr[k].first;
						int y = updateArr[k].second;
						arr[x][y] = avg;
					}
					sumArr.clear();
					updateArr.clear();
				}
			}
		}

		memset(visited, 0, sizeof(visited));
		if (flag == false)
		{
			break;
		}
		cnt++;
	}
	cout << cnt;
}
