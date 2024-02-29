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

int R, C, K;
char aarr[6][6];
bool visited[6][6];

vector<vector<pair<int, int>>> arrList;
vector<pair<int, int>> posArr;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void combi(int x, int y, vector<pair<int, int>> arr)
{
	if (arr.size() == K)
	{
		if (arr[K - 1].first == 0 && arr[K - 1].second == C-1)
		{
		arrList.push_back(arr);
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C && aarr[nx][ny] == '.'&& visited[nx][ny] == false)
		{
			arr.push_back({ nx, ny });
			visited[nx][ny] = true;
			combi(nx, ny, arr);
			visited[nx][ny] = false;
			arr.pop_back();
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> aarr[i][j];
		}
	}

	posArr.push_back({ R - 1,0 });
	visited[R - 1][0] = true;
	combi(R - 1, 0, posArr);
	cout << arrList.size(); 

}
