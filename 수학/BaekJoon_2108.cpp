#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <math.h>

using namespace std;

vector<int> arr;
int arrCnt[8001] = {};
vector<int> mxArr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int mxCnt = 0;
	int mn = 4001;
	int mx = -4001;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		arr.push_back(n);
		if (mn > n)
		{
			mn = n;
		}
		if (mx < n)
		{
			mx = n;
		}
		arrCnt[n+4000]++;
	}

	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	int average = round((double)sum / N);
	cout << average << '\n';

	sort(arr.begin(), arr.end());

	cout << arr[arr.size() / 2] << '\n';
	for (int i = 0; i < N; i++)
	{
		if (arrCnt[arr[i] + 4000] > mxCnt)
		{
			mxCnt = arrCnt[arr[i]+4000];
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (arrCnt[arr[i]+4000] == mxCnt)
		{
			mxArr.push_back(arr[i]);	
		}
	}

	sort(mxArr.begin(), mxArr.end());
	mxArr.erase(unique(mxArr.begin(), mxArr.end()), mxArr.end());
	if (mxArr.size() > 1)
	{
		cout << mxArr[1] << '\n';
	}
	else
	{
		cout << mxArr[0] << '\n';
	}
	
	cout <<  mx - mn;
}
