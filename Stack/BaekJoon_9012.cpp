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

stack<char> ms;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '(')
			{
				ms.push(s[j]);
			}
			else
			{
				if (ms.empty())
				{
					cout << "NO" << '\n';
					flag = true;
					break;
				}
				else
				{
					ms.pop();
				}
			}
		}
		if (ms.empty() && flag != true)
		{
			cout << "YES" << '\n';
		}
		else if (flag != true)
		{
			cout << "NO" << '\n';
		}
		while (!ms.empty())
		{
			ms.pop();
		}
		flag = false;
	}

}
