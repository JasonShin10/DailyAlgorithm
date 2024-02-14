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

vector<pair<int, string>> arr;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int teamNum;
		string s;
		cin >> teamNum >> s;
		arr.push_back({ teamNum,s });
	}
	int team1 = 0;
	int team2 = 0;
	int team1Cnt = 0;
	int team2Cnt = 0;
	bool isWinning1 = false;
	bool isWinning2 = false;
    int k = 0;

	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			string sm;
			sm += arr[k].second[0];
			sm += arr[k].second[1];
			string ss;
			ss += arr[k].second[3];
			ss += arr[k].second[4];

			int m = stoi(sm);
			int s = stoi(ss);
			// 골을 넣었을때
			if (i == m && j == s)
			{
				// 첫번째 팀이 골을 넣었다면
				if (arr[k].first == 1)
				{
					// 첫번째 팀 점수 증가
					team1Cnt++;
					// 첫번째 팀이 이기고 있으면?
					if (team1Cnt > team2Cnt)
					{
						// 첫번째 팀 시간 증가
						team1++;
						isWinning1 = true;
						isWinning2 = false;
					}
					else if (team1Cnt < team2Cnt)
					{
						team2++;
					}
					else if (team1Cnt == team2Cnt)
					{
						// 동점이면 이기는 팀 없음
						isWinning1 = false;
						isWinning2 = false;
					}
				}
				else
				{
					// 두번째 팀 점수 증가
					team2Cnt++;
					// 두번째 팀이 이기고 있으면?
					if (team1Cnt < team2Cnt)
					{
						// 두번째 팀 시간 증가
						team2++;
						isWinning1 = false;
						isWinning2 = true;
					}
					else if (team1Cnt > team2Cnt)
					{
						team1++;
					}
					// 동점이면 이기는 팀 없음
					else if (team1Cnt == team2Cnt)
					{
						isWinning1 = false;
						isWinning2 = false;
					}
				}
				if (k + 1 < arr.size())
				{
					k += 1;
				}
			}
			// 골 는상태가 아니면
			else
			{
				// 1번팀이 이기고 있으면
				if (isWinning1 == true)
				{
					// 1번팀 시간 증가
					team1++;
				}
				// 2번팀이 이기고 있으면
				else if (isWinning2 == true)
				{
					// 2번팀 시간 증가
					team2++;
				}
			}
			
		}

	}
	int m = team1 / 60;
	int s = team1 % 60;
	string sm = to_string(m);
	if (sm.size() == 1)
	{
		sm = '0' + sm;
	}
	string ss = to_string(s);
	if (ss.size() == 1)
	{
		ss = '0' + ss;
	}
	cout << sm << ':' << ss << '\n';
	m = team2 / 60;
	s = team2 % 60;
	sm = to_string(m);
	if (sm.size() == 1)
	{
		sm = '0' + sm;
	}
	ss = to_string(s);
	if (ss.size() == 1)
	{
		ss = '0' + ss;
	}
	cout << sm << ':' << ss;
}
