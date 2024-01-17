#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N,M;
	cin >> N >> M;
	vector<int> arr;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	int l = 0;
	int h = arr.size() - 1;

	while (l < h)
	{
		if (arr[l] + arr[h] == M)
		{
			cnt++;
			l++;
			h--;
		}
		else if (arr[l] + arr[h] > M)
		{
			h--;
		}
		else
		{
			l++;
		}
	}
	cout << cnt;
}
