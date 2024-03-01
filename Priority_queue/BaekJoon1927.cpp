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

priority_queue<int, vector<int>, greater<int>> p;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			if (p.empty())
			{
				cout << 0 << '\n';
			}
			else
			{

				cout << p.top() << '\n';
			p.pop();
			}
		}
		else
		{
		p.push(n);
		}
	}
}
