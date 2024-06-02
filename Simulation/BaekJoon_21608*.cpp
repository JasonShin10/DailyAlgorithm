#include <iostream>
#include <vector>
#include <map>
using namespace std;

int N;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int arr[24][24] = {};

int mx = -1e9;
int emx = -1e9;
vector<vector<int>> nums;
map<int, vector<int>> mp;
int main() {
	cin >> N;
	for (int i = 0; i < N * N; i++)
	{
		vector<int> v;
		nums.push_back(v);
	}

	for (int i = 0; i < nums.size(); i++)
	{
		vector<int> v;
		for (int j = 0; j < 5; j++)
		{
			int n; 
			cin >> n;
			nums[i].push_back(n);
			if (j != 0)
			{
				v.push_back(n);
			}
		}
		mp[nums[i][0]] = v;
	}


	for (int i = 0; i < nums.size(); i++)
	{
		int n = nums[i][0];
		int x = N+1;
		int y = N+1;
		int mx = -1e9;
		int emx = -1e9;

		for (int r = 1; r <= N; r++)
		{
			for (int c = 1; c <= N; c++)
			{

				int cnt = 0;
				int eCnt = 0;
				// 비어있는 칸 중에서
				if (arr[r][c] != 0)
				{
					continue;
				}
				// 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
				for (int j = 0; j < 4; j++)
				{
					int nx = r + dx[j];
					int ny = c + dy[j];
					if (nx > 0 && nx <= N && ny > 0 && ny <= N)
					{
						if (arr[nx][ny] == 0)
						{
							eCnt++;
							continue;
						}
						for (int k = 1; k < nums[i].size(); k++)
						{
							if (arr[nx][ny] == nums[i][k])
							{
								cnt++;
								continue;
							}
						}
					}
				}
				if (mx == cnt)
				{
					if (emx == eCnt)
					{
						if (x == r)
						{
							if (c < y)
							{
								x = r;
								y = c;
							}
						}
						else if (r < x)
						{
							x = r;
							y = c;
						}
					}
					else if (emx < eCnt)
					{
						emx = eCnt;
						x = r;
						y = c;
					}
				}
				else if (mx < cnt)
				{
					mx = cnt;
					emx = eCnt;
					x = r;
					y = c;
				}
			}
		}
		arr[x][y] = n;
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int sum = 1;
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx > 0 && nx <= N && ny > 0 && ny <= N)
				{
					for (int l = 0; l < mp[arr[i][j]].size(); l++)
					{
						if (arr[nx][ny] == mp[arr[i][j]][l])
						{
							cnt++;
						}
					}

				}
			}
			if (cnt == 0)
			{
				continue;
			}
			for (int k = 2; k <= cnt; k++)
			{
				sum *= 10;
			}
			ans += sum;
			
		}
	}
	cout << ans;
	return 0;
}
