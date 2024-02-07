#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<long long> arr;
int mx = -1e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		long long K;
		cin >> K;
		arr.push_back(K);
		if (mx < K)
		{
			mx = K;
		}
	}
	long long l = 1;
	long long r = mx;
	long long ans = 0;
	while (l <= r)
	{
		long long sum = 0;
		long long m = (l + r) / 2;
		for (int i = 0; i < K; i++)
		{
			sum += arr[i] / m;
		}

		if (sum >= N)
		{
			l = m + 1;
			ans = m;
		}
		else
		{
			r = m - 1;
		}
	}

	cout << ans;
}
