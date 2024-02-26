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

queue<int> mq;

bool visited[100004];
int cnt[100004] = {};
int check[100004] = {};
int ans;
int N, K;
void BFS()
{
	while (!mq.empty())
	{
		int x = mq.front();
		mq.pop();
		for (int i = 0; i < 3; i++)
		{
			int nx = 0;
			switch (i) {
			case 0:
				nx = x + 1;
				break;
			case 1:
				nx = x - 1;
				break;
			case 2:
				nx = 2 * x;
				break;
			}
			if (nx >= 0 && nx < 100004)
			{
				if (visited[nx] == false)
				{
					mq.push(nx);
					check[nx] = check[x] + 1;
					visited[nx] = true;
					cnt[nx] = cnt[x];
				}
				else if (check[nx] == check[x] + 1)
				{
					cnt[nx] += cnt[x];
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	if (N == K)
	{
		cout << 0 << '\n';
		cout << 1;
		return 0;
	}
	mq.push(N);
	visited[N] = true;

	cnt[N] = 1;
	check[N] = 1;
	BFS();

	cout << check[K]-1 << '\n';
	cout << cnt[K];
	
}
