#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<int> v;
int x;
int cnt;
int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	cin >> x;

	sort(v.begin(), v.end());

	int l = 0;
	int r = N - 1;
	while (l < r)
	{
		if (v[l] + v[r] == x)
		{
			l++;
			cnt++;
		}
		else if(v[l] + v[r] < x)
		{
			l++;
		}
		else if (v[l] + v[r] > x)
		{
			r--;
		}
	}

	cout << cnt;
}
