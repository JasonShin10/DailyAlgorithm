#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

using namespace std;

queue<int> mq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		mq.push(i);
	}
	cout << "<";
	while (1)
	{
		for (int i = 0; i < K - 1; i++)
		{
			mq.push(mq.front());
			mq.pop();
		}

		cout << mq.front();

		mq.pop();
		if (mq.empty())
		{
			break;
		}
		else
		{
			cout << ", ";
		}
	}
	cout << ">";
}
