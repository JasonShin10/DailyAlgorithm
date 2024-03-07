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

vector<int> arr;
int cnt = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,x;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		arr.push_back(n);
	}
	cin >> x;
	sort(arr.begin(), arr.end());

	int l = 0;
	int r = arr.size()-1;

	while (l < r)
	{
		int m = arr[l] + arr[r];
		
		if (m == x)
		{
			cnt++;
			l++;
		}
		else if (m > x)
		{
			r--;
		}
		else
		{
			l++;
		}
	}

	cout << cnt;

}
