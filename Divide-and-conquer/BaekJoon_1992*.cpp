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


vector<string> arr;
string s;

int N;
void check(int x, int y, int size);
void solve(int x, int y, int size)
{
	int div = size / 2;
	s += "(";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			check(x + div * i, y + div * j, div);
		}
	}
	s += ")";
}

void check(int x, int y, int size)
{
	int check = arr[x][y];
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (check != arr[i][j])
			{
				solve(x, y, size);
				return;
			}
		}
	}

	s += check;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string color;
		cin >> color;
		arr.push_back(color);
	}

	check(0, 0, N);
	cout << s;

}
