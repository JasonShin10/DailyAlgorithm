#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

vector<int> arr;
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int cnt = K;
	for (int i = 1; i <= N; i++)
	{
		arr.push_back(i);
	}
	while (!arr.empty())
	{
		while (K > arr.size())
		{
			K -= arr.size();
		}
		ans.push_back(arr[K-1]);
		arr.erase(arr.begin() + K-1);
		K += cnt - 1;
	}
	cout << "<";
	for (int i = 0; i < N; i++)
	{
		cout << ans[i];
		if (i != N - 1)
		{
			cout << ", ";
		}
	}
	cout << ">";
}
