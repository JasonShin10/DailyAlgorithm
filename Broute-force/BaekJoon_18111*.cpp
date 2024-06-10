#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int arr[504][504] = {};

int N, M, B;
int main() {
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	int inven = B;
	bool flag = false;
	int mn = 1e9;
	vector<int> v;
	for (int h = 0; h <= 256; h++)
	{
		B = inven;
		flag = false;
		ans = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] != h)
				{
					if (arr[i][j] - h > 0)
					{
						B += arr[i][j] - h;
						ans += 2 * (arr[i][j] - h);
					}
					else if (arr[i][j] - h < 0)
					{

							B += (arr[i][j] - h);
							ans -= (arr[i][j] - h);						
					}
				}
			}
		}
		if (B < 0)
		{
			flag = true;
		}


		if (flag == false)
		{
			if (ans < mn)
			{
				mn = ans;
				v.clear();
				v.push_back(h);
			}
			if (ans == mn)
			{
				v.push_back(h);
			}
		}
	}

	sort(v.begin(), v.end(), greater<>());
	int h = 0;
	if (!v.empty())
	{
		h = v[0];
	}
	cout << mn << " " << h;

	return 0;
}
