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

int N;
int pre = -1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int et, ex;
		cin >> et >> ex;
		v.push_back({ et,ex });
	}
	sort(v.begin(), v.end());
	pre = v[0].first + v[0].second;
	for (int i = 1; i < v.size(); i++)
	{
		if (pre < v[i].first)
		{
			pre = v[i].first + v[i].second;
		}
		else
		{
			pre += v[i].second;
		}
	}
	cout << pre;
}
