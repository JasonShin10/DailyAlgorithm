#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N,M;
vector<int> v;
int mx = -1e9;

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	int sum = 0;

	int r = M-1;

	for (int i = 0; i < N; i++)
	{
		sum += v[i];
		if (i == r)
		{
			if (mx < sum)
			{
				mx = sum;
			}
		}

		if (i > r)
		{
			sum -= v[i - (r+1)];
			if (mx < sum)
			{
				mx = sum;
			}
		}
	}

	cout << mx;
}
