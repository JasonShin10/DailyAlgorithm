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
int N, M;
int arr[51][51] = {};
vector<vector<int>> chickenList;
vector<pair<int, int>> chickenPos;
vector<pair<int, int>> housePos;

void combi(int start, vector<int> v)
{
	if (v.size() == M)
	{
		chickenList.push_back(v);
		return;
	}
	for (int i = start + 1; i < chickenPos.size(); i++)
	{
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				housePos.push_back({ i,j });
			if (arr[i][j] == 2)
				chickenPos.push_back({ i,j });
		}
	}
	int ans = 1e9;
	vector<int> v;
	combi(-1, v);
	for (int i = 0; i < chickenList.size(); i++)
	{
		// 도시의 치킨 거리 = 치킨 거리들의 합
		int ret = 0;
		for (int j = 0; j < housePos.size(); j++)
		{
			// 치킨 거리 = 집과 가장 가까운 치킨집과의 거리
			int mn = 1e9;
			for (auto ch : chickenList[i])
			{
				int dist = abs(housePos[j].first - chickenPos[ch].first) + abs(housePos[j].second - chickenPos[ch].second);
			    mn = min(mn, dist);
			}
			ret += mn;
		}
		ans = min(ans, ret);
	}

	cout << ans;



}
