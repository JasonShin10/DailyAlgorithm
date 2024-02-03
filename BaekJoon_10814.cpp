#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

multimap<int, string> mp;
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		mp.insert(make_pair(age,name));
	}

	for (auto element : mp)
	{
		cout << element.first << " " << element.second << "\n";
	}
}
