#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	string s = "666";
	while (1)
	{
		if (s.find("666") != string::npos)
		{
			N--;
		}
		if (N == 0)
		{
			cout << s;
			break;
		}
		
	    int tmp = stoi(s);
		tmp++;
		s = to_string(tmp);
	}
}
