#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int cnt[26] = {};
int main()
{
	string s;
	cin >> s;
	string ret;
	int oddCnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		cnt[s[i] - 'A']++;
	}

	for (int i = 25; i >=0; i--)
	{
		if (cnt[i] % 2 == 1)
		{
			oddCnt++;
			if (oddCnt > 1)
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			while (cnt[i] > 1)
			{
				ret = char(i + 'A') + ret;
				ret += char(i + 'A');
				cnt[i] -= 2;
			}
			ret.insert(ret.size() / 2, 1, char(i + 'A'));
		}
		else
		{
			while (cnt[i] > 0)
			{
				ret = char(i + 'A') + ret;
				ret += char(i + 'A');
				cnt[i] -= 2;
			}
		}
	}
	cout << ret;
}
