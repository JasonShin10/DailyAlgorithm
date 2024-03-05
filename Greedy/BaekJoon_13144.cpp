#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <cstring>
#include <stack>

using namespace std;
int arr[100004];
bool visited[100004];
long long ret;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int s = 0;
	int e = 0;
	for (int i = 0; i < N; i++)
	{
		while (e < N)
		{
			if (visited[arr[e]])
				break;
			visited[arr[e]] = 1;
			e++;
		}
		ret += (e - i);
		visited[arr[i]] = 0;
	}
	cout << ret;
}
