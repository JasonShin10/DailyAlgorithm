#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int arr[501][501] = {};
bool visited[501][501] = {};
// 위, 아래, 오른쪽, 왼쪽
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int pictureCnt = 0;
int cnt = 0;
int mx = 0;

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
			if (nx >=0 && nx<N && ny>=0 && ny <M && arr[nx][ny] == 1 )
			{
				if (visited[nx][ny] != true)
				{
				mq.push({ nx,ny });
				cnt++;
				visited[nx][ny] = true;
				}
			}
		}
	}
}

int main()
{
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
			if (arr[i][j] == 1 && visited[i][j] == false)
			{
				mq.push({ i,j });
				visited[i][j] = true;
				cnt++;
				BFS();
				pictureCnt++;
				if (cnt > mx)
				{
					mx = cnt;
				}
				cnt = 0;
			}
		}
	}

	cout << pictureCnt << "\n";
	cout << mx;
}
