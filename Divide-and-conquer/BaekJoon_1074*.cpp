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

int N, r, c;
int x, y, ans;
void FindTarget(int x, int y, int n)
{
	if (x == r && y == c)
	{
		cout << ans << "\n";
		return;
	}

	if (r < x + n && r >= x && c < y + n && c >= y)
	{
		FindTarget(x, y, n / 2);
		FindTarget(x, y + n / 2, n / 2);
		FindTarget(x + n / 2, y, n / 2);
		FindTarget(x + n / 2, y + n / 2, n / 2);
	}
	else ans += n * n;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> r >> c;
	FindTarget(0, 0, (1 << N));

}
