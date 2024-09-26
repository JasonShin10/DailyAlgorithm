#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int N, S;
vector<int> v;
vector<int> cv;
int sum = 0;

int cnt = 0;
void combi(int n, int start)
{
	if (cv.size() == n)
	{
		for (int i = 0; i < cv.size(); i++)
		{
			sum += cv[i];
		}
		if (sum == S)
		{
		cnt++;
		}
		sum = 0;
		return;
	}

	for (int i = start+1; i < v.size(); i++)
	{
		
			cv.push_back(v[i]);

			combi(n,i);
			cv.pop_back();

		
	}
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		combi(i,-1);
	}


	cout << cnt;

}
