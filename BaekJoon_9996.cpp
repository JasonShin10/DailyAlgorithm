#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;
	string l;
	string r;
	bool isStar =false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*')
		{
			isStar = true;
			continue;
		}

		if (isStar == false)
		{
			l += s[i];
		}
		else
		{
			r += s[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		if (a.size() < l.size() + r.size())
		{
			cout << "NE" << "\n";
			continue;
		}
		if (a.substr(0, l.size()) == l &&
			a.substr(a.size() - r.size()) == r)
		{
			cout << "DA" << "\n";
		}
		else
		{
			cout << "NE" << "\n";
		}
	}
}
