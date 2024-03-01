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
map<string, int> mp;
vector<string> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		mp[s]++;
	}
	for (int j = 0; j < M; j++)
	{
		string s;
		cin >> s;
		mp[s]++;
	}
	int cnt = 0;
	for (auto element : mp)
	{
		if (element.second > 1)
		{
			cnt++;
			v.push_back(element.first);
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}
