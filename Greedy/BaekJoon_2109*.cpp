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
vector<pair<int, int>> arr;
int ret;

priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int p, d;
		cin >> p >> d;
		arr.push_back({ d,p });
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++)
	{
		pq.push(arr[i].second);
		if (pq.size() > arr[i].first)
		{
			pq.pop();
		}
	}
	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	}

	cout << ret << '\n';
}
