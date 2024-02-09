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

int arr[101][101] = {};

queue<pair<int, int>> mq;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0,0,1,-1 };
int M, N, K;
bool visited[101][101] = {};
int cnt;
int area;
vector<int> mv; 

void BFS(int a, int b)
{
	mq.push({ a,b });

	while (!mq.empty())
	{
		int x = mq.front().first;
		int y = mq.front().second;
		mq.pop();
		for(int i=0; i<4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && ny >= 0 && nx < M && ny < N && visited[nx][ny] == false && arr[nx][ny] != 1)
			{
				mq.push({ nx,ny });
				visited[nx][ny] = true;
				area++;
			}
		}


	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				arr[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != 1 && visited[i][j] == false)
			{
				visited[i][j] = true;
				area++;
			    BFS(i, j);
				cnt++;
				mv.push_back(area);
			}
			area = 0;
		}
	}
	cout << cnt << '\n';
	sort(mv.begin(), mv.end());
	for (int i = 0; i < mv.size(); i++)
	{
		cout << mv[i] << " ";
	}

}
