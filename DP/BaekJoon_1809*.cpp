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
#include <cctype>

using namespace std;

int N;
int arr[104][104] = {};
long long dp[104][104] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	dp[0][0] = 1;

	for(int i=0; i< N; i++)
		for (int j = 0; j < N; j++)
		{
			long long jump = arr[i][j];
		
			if(i+jump < N && i != N-1)
			{
				dp[i + jump][j] += dp[i][j];
			}

			if (j + jump < N && j != N - 1)
			{
				dp[i][j + jump] += dp[i][j];
			}
		}

	cout << dp[N - 1][N - 1];
	return 0;
}
