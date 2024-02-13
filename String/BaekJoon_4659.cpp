#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <cstring> 

using namespace std;

char gArr[] = { 'a','e','i','o','u' };
bool hasGather = false;
bool isContinue = false;
bool isSameTwice = false;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		string s;
		cin >> s;
		if (s == "end")
		{
			return 0;
		}
		hasGather = false;
		isContinue = false;
		isSameTwice = false;

		bool arr[26] = {};

		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (s[i] == gArr[j])
				{
					hasGather = true;
					arr[i] = true;
				}
			}
			if (s[i+1] != s.size() && s[i] == s[i + 1])
			{
				if (s[i] != 'e' && s[i] != 'o')
				{
					isSameTwice = true;
				}
			}
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (i+2 < s.size() && arr[i] == true && arr[i + 1] == true && arr[i + 2] == true)
			{
				isContinue = true;
			}
			if (i + 2 < s.size() && arr[i] == false && arr[i + 1] == false && arr[i + 2] == false)
			{
				isContinue = true;
			}
		}
		
		if (hasGather == true && isSameTwice == false && isContinue == false)
		{
			cout << '<' << s << '>' << " is acceptable." << '\n';
		}
		else
		{
			cout << '<' << s << '>' << " is not acceptable." << '\n';
		}
	}
}
