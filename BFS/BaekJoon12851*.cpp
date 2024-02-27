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

int N, K;
queue<int> mq;
int visited[200004] = {};
int pre[200004] = {};
vector<int> v;
void BFS()
{
	while (!mq.empty())
	{
		int x = mq.front();
		mq.pop();
		if (x == K)
		{
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			int nx;
			switch (i)
			{
			case 0:
				nx = x + 1;
				break;
			case 1:
				nx = x - 1;
				break;
			case 2:
				nx = x * 2;
				break;
			}
			if (nx >= 0 && nx < 200004 && visited[nx] == 0)
			{
				visited[nx] = visited[x] + 1;
				mq.push(nx);
				pre[nx] = x;
			}
		}
	}
	for (int i = K; i != N; i = pre[i])
	{
		v.push_back(i);
	}
	v.push_back(N);
	reverse(v.begin(), v.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 수빈이가 있는 위치 N
	// 동생이 있는 위치 K
	cin >> N >> K;
	vector<int> arr;
	mq.push(N);
	visited[N] = 1;
	BFS();
	cout << visited[K]-1 << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}
