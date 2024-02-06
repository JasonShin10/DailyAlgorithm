#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

vector<int> cards;
vector<int> nums;
map<int, int> mp;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		cards.push_back(a);
		mp[a]++;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		nums.push_back(a);
	}

	for (auto element : nums)
	{
		cout << mp[element] << " ";
	}


}
