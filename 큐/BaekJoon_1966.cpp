#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		priority_queue<int> pq;
		queue<pair<int, int>> mq;
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			int ipt;
			cin >> ipt;
			mq.push({ i,ipt });
			pq.push(ipt);
		}
		int cnt = 0;
		while (!pq.empty())
		{
			if (mq.front().second == pq.top() && mq.front().first == M)
			{
				mq.pop();
				pq.pop();
				cnt++;
				cout << cnt << '\n';
				break;
			}
			else if (mq.front().second == pq.top())
			{
				mq.pop();
				pq.pop();
				cnt++;
			}
			else if(mq.front().second != pq.top())
			{
				mq.push(mq.front());
				mq.pop();
			}
		}
	}
}
