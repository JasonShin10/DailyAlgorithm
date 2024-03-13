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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<string> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	vector<char> ans(v[0].size());
	if (N == 1)
	{
		cout << v[0];
		return 0;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[0][j] == v[i][j] && ans[j] != '?')
			{
				ans[j] = v[i][j];
			}
			else
			{
				ans[j] = '?';
			}
		}
	}
	string s = "";
	for (int i = 0; i < v[0].size(); i++)
	{
		s += ans[i];
	}
	cout << s;
}
