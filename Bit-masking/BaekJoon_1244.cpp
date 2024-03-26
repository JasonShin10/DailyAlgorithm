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
#include <cctype>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M;
	cin >> M;
	int n;
	string s;
	int set=0;
	while (M--)
	{
		cin >> s;
		if (s == "add")
		{
			cin >> n;
			set |= (1 << (n - 1));
		}
		else if (s == "remove")
		{
			cin >> n;
			set &= ~(1 << (n - 1));
		}
		else if (s == "check")
		{
			cin >> n;
			if (set & (1 << (n - 1)))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (s == "toggle")
		{
			cin >> n;
			set ^= (1 << (n - 1));
		}
		else if (s == "all")
		{
			set = (1 << 20) - 1;
		}
		else if (s == "empty")
		{
			set = 0;
		}

	}
}
