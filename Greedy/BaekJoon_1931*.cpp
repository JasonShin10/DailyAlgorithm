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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		v.push_back({ end, start });
	}

	sort(v.begin(), v.end());
	int pre;
	int cnt = 1;
	pre = v[0].first;
	for (int i = 1; i < N; i++)
	{
		if (v[i].second >= pre)
		{
			pre = v[i].first;
			cnt++;
		}
	}

	cout << cnt;

}
