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

vector<int> arr;

int N, M, J;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> J;
	for (int i = 0; i < J; i++)
	{
		int n;
		cin >> n;
		arr.push_back(n);
	}

	int l = 1;
	int r = M;
	int move = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > r)
		{
			move += arr[i] - r;
			l += arr[i] - r;
			r = arr[i];
		}
		else if(arr[i] < l)
		{
			move += l - arr[i];
			r -= l - arr[i];
			l = arr[i];
		}
	}

	cout << move;
}
