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

int arr[3] = {};
int dmg[6][3] = { {1,3,9},{1,9,3},{9,1,3}, {9,3,1},{3,1,9},{3,9,1} };
int visited[64][64][64] = {};

struct A
{
	int a;
	int b;
	int c;
};
queue<A> mq;
void BFS()
{
	while (!mq.empty())
	{
		int x = mq.front().a;
		int y = mq.front().b;
		int z = mq.front().c;
		mq.pop();
		if (visited[0][0][0])
		{
			
			break;
		}
		for (int i = 0; i < 6; i++)
		{
			int nx = x - dmg[i][0];
			if (nx < 0)
			{
				nx = 0;
			}
			int ny = y - dmg[i][1];
			if (ny < 0)
			{
				ny = 0;
			}
			int nz = z - dmg[i][2];
			if (nz < 0)
			{
				nz = 0;
			}

			if (visited[nx][ny][nz] != true)
			{
				mq.push({ nx,ny,nz });
				visited[nx][ny][nz] = visited[x][y][z] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	mq.push({ arr[0],arr[1],arr[2] });
	visited[arr[0]][arr[1]][arr[2]] = 1;
	BFS();
	cout << visited[0][0][0]-1;
}
