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
typedef long long ll;
ll ret;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<pair<ll, ll>> gem(N);
	vector<ll> bag(K);

	for (int i = 0; i < N; i++)
	{
		cin >> gem[i].first >> gem[i].second;
	}

	for (int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}

	sort(gem.begin(), gem.end());
	sort(bag.begin(), bag.end());

	priority_queue<ll> pq;

	int j = 0;


	for (int i = 0; i < K; i++) {
		while (j < N && gem[j].first <= bag[i])
		{
			pq.push(gem[j++].second);
		}
		if (pq.size())
		{
			ret += pq.top();
			pq.pop();
		}

	}
	cout << ret << "\n";
}
