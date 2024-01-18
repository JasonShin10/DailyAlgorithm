#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> arr;
	stack<char> myStack;
	int cnt = N;

	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		arr.push_back(a);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (!myStack.empty() && myStack.top() == arr[i][j])
			{
				myStack.pop();
			}
			else
			{
			    myStack.push(arr[i][j]);
			}
		}
		if (!myStack.empty())
		{
			cnt--;
		}
		while (!myStack.empty())
		{
			myStack.pop();
		}
	}
	cout << cnt;
}
