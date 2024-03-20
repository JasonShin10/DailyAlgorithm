#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int N;
int dp[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<int> v(N);
	int sum = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	int mx = v[0];
	dp[0] = v[0];
	for (int i = 1; i < N; i++)
	{
		dp[i] = max(v[i], dp[i-1] + v[i]);
		mx = max(mx, dp[i]);
	}
	cout << mx;
}
