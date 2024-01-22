#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int mx=-1e9;

	int sum=0;
	vector<int> sArr;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		sum += n;
		sArr.push_back(sum);
	}

	for (int i = K-1; i < N; i++)
	{
		int num = sArr[i];
		if (i >= K) {
			num -= sArr[i - K];
		}
		mx = max(mx, num);
	}
	cout << mx;
}
