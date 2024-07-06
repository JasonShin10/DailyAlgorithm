#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cctype>
#include <string>

using namespace std;

vector<deque<char>> t;
int K;
vector<pair<int, int>> v;

void rightRot(int num, int d,char ori)
{
	if (num > 3)
	{
		return;
	}

	if (d == 1)
	{
		int nd = -1;
		char origin = t[num][2];
		if (ori != t[num][6])
		{
			char temp = t[num].back();
			t[num].pop_back();
			t[num].push_front(temp);
			
			rightRot(num + 1, nd,origin);
		}
		
		
	}
	else
	{
		int nd = 1;
		char origin = t[num][2];
		if (ori != t[num][6])
		{
			char temp = t[num].front();
			t[num].pop_front();
			t[num].push_back(temp);
			rightRot(num + 1, nd, origin);
		}
		
		
	}
}

void leftRot(int num, int d, char ori)
{
	if (num < 0)
	{
		return;
	}

	if (d == 1)
	{
		int nd = -1;
		char origin = t[num][6];
		if (ori != t[num][2])
		{
			char temp = t[num].back();
			t[num].pop_back();
			t[num].push_front(temp);
			
			leftRot(num-1, nd,origin);
		}
		
	}
	else
	{
		int nd = 1;
		char origin = t[num][6];
		if (ori != t[num][2])
		{
			char temp = t[num].front();
			t[num].pop_front();
			t[num].push_back(temp);
			leftRot(num-1, nd, origin);
		}
		
	}
}

int main() {

	string n;
	for (int i = 0; i < 4; i++)
	{
		deque<char> c;
		cin >> n;
		for (int j = 0; j < 8; j++)
		{
			c.push_back(n[j]);
		}
		t.push_back(c);
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	// 톱니바퀴 선택
	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i].first-1;
		int b = v[i].second;
		int nd = 0;
		char rightOri = t[a][2];
		char leftOri = t[a][6];

		// 오른쪽
		if (b == 1)
		{
			char temp = t[a].back();
			nd = -1;
			t[a].pop_back();
			t[a].push_front(temp);
		}
		else
		{
			char temp = t[a].front();
			nd = 1;
			t[a].pop_front();
			t[a].push_back(temp);

		}
		rightRot(a+1,nd, rightOri);
		leftRot(a-1,nd, leftOri);

	}
	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0 && t[i][0] == '1')
		{
			answer += 1;
		}
		else if (i == 1 && t[i][0] == '1')
		{
			answer += 2;
		}
		else if (i == 2 && t[i][0] == '1')
		{
			answer += 4;
		}
		else if (i == 3 && t[i][0] == '1')
		{
			answer += 8;
		}
	}

	cout << answer;
}
