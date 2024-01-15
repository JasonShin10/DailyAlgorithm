#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; int j = s.size() - 1; i <= j;)
	{
		if (s[i] == s[j])
		{
			i++;
			j--;
		}
		else
		{
			cout << 0;
			return;
		}
	}
	cout << 1;
}
