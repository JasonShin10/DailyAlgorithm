#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;

	int N;
	cin >> N;

	for (int i = 5; i <= N; i *= 5)
	{
		ans += N / i;
	}
	cout << ans << '\n';
	
}
