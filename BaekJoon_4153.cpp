#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<int> arr;
int main() {
	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			return 0;
		}
		arr.push_back(a);
		arr.push_back(b);
		arr.push_back(c);
		sort(arr.begin(), arr.end());
		if (pow(arr[2],2) == pow(arr[0],2) + pow(arr[1],2))
		{
			cout << "right" << "\n";
		}
		else
		{
			cout << "wrong" << "\n";
		}
		arr.clear();
	}
}
