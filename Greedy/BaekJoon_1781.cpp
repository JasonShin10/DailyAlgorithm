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

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int d, p;
		cin >> d >> p;

		v.push_back({ d,p});
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
		{
			pq.pop();
		}
	}
	int ans = 0;
	while (pq.size())
	{
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
}
