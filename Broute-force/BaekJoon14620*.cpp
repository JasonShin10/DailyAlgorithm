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

int arr[11][11] = {};
bool visited[11][11] = {};
vector<pair<int, int>> flowers;
vector<vector<pair<int, int>>> combiList;
int N;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


bool flag;
void combi(vector<pair<int, int>> flowers)
{
	if (flowers.size() == 3)
	{
		combiList.push_back(flowers);
		return;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			flag = false;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				// 4방향 공간 검사
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] == true)
				{
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				flowers.push_back({ i,j });
				visited[i][j] = true;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					visited[nx][ny] = true;
				}
				combi(flowers);
				flowers.pop_back();
				visited[i][j] = false;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					visited[nx][ny] = false;
				}
			}
		}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int mn = 1e9;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	combi(flowers);
	for (int i = 0; i < combiList.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			int x = combiList[i][j].first;
			int y = combiList[i][j].second;
			sum += arr[x][y];
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				sum += arr[nx][ny];
			}
		}
		if (mn > sum)
		{
			mn = sum;
		}
	}
	cout << mn;
}
