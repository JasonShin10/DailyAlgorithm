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

	int N, K;
	cin >> N >> K;
	vector<int> tab;
	vector<int> v(K);

	int visited[104] = {};
	for (int i = 0; i < K; i++)
	{
		cin >> v[i];
	}

	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (!visited[v[i]])
		{
			if (tab.size() == N)
			{
				int nextPick;
				int mx = 0;
				for (auto e : tab)
				{
					int pos = 1e9;
					// e랑 같은 전기가 있는지 찾는다.
					// 있다면 순서를 기록한다.
					for (int j = i + 1; j < v.size(); j++)
					{
						if (e == v[j])
						{
							pos = j;
							break;
						}
					}
					// 제일 큰 순서 찾기
					if (mx < pos)
					{
						mx = pos;
						// 뽑아야할 전기
						nextPick = e;
					}
				}
				visited[nextPick] = 0;
				tab.erase(find(tab.begin(), tab.end(), nextPick));
				cnt++;
			}
		tab.push_back(v[i]);
		visited[v[i]] = 1;
		}
	}

	cout << cnt;
}
