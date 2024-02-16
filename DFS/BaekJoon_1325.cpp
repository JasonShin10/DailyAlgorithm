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

vector<vector<int>> arr;
int cnt = 0;
int mx = -1e9;
vector<pair<int, int>> ansArr;
int visited[10001];
void DFS(int n)
{

	for (int i = 0; i < arr[n].size(); i++)
	{
		if (visited[arr[n][i]] != true)
		{
			visited[arr[n][i]] = true;
			cnt++;
			DFS(arr[n][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	arr.resize(N + 1, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[b].push_back(a);
	}

	for (int i = 0; i <= N; i++)
	{
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		visited[i] = true;
		DFS(i);
		ansArr.push_back({ cnt,i });
	}

	sort(ansArr.begin(), ansArr.end());

	for (int i = 0; i <= N; i++)
	{
		if (ansArr[N].first == ansArr[i].first)
		{
			cout << ansArr[i].second << " ";
		}
	}
}
