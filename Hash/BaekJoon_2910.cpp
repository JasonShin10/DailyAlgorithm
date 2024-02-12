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

vector<int> oriArr;
vector<int> arr;

map<int, int> mp1;
bool compare(int a, int b)
{
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (find(oriArr.begin(), oriArr.end(), n) == oriArr.end())
		{
			oriArr.push_back(n);
		}
		mp1[n]++;
	}
	
	for (auto element : mp1)
	{
		arr.push_back({element.second});
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < oriArr.size(); j++)
		{
			if (mp1[oriArr[j]] == arr[i])
			{
				for (int k = 0; k < mp1[oriArr[j]]; k++)
				{
					cout << oriArr[j] << " ";
				}
				mp1[oriArr[j]] = 0;
 			}
		}
	}
}
