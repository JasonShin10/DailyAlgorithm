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

int N, mx;
string s;

void cal(int cur, int ret)
{
    if (cur > N)
    {
        if (ret > mx)
        {
            mx = ret;
        }
        return;
    }
    if (cur + 2 < N)
    {
        int tmp1, tmp2, tret;
        tmp1 = (s[cur] - '0');
        tmp2 = (s[cur + 2] - '0');
        if (s[cur + 1] == '+')
        {
            tret = tmp1 + tmp2;
        }
        else if (s[cur + 1] == '-')
        {
            tret = tmp1 - tmp2;
        }
        else if (s[cur + 1] == '*')
        {
            tret = tmp1 * tmp2;
        }
        if (cur == 0)
        {
            cal(4, tret);
        }
        else {
            if (s[cur - 1] == '+')
            {
                cal(cur + 4, ret + tret);
            }
            else if (s[cur - 1] == '-')
            {
                cal(cur + 4, ret - tret);
            }
            else if (s[cur - 1] == '*')
            {
                cal(cur + 4, ret * tret);
            }
        }
    }

    int num = s[cur] - '0';
    if (cur == 0)
    {
        cal(2, num);
    }
    else
    {
        if (s[cur - 1] == '+')
        {
            cal(cur + 2, ret + num);
        }
        else if (s[cur - 1] == '-')
        {
            cal(cur + 2, ret - num);
        }
        else if (s[cur - 1] == '*')
        {
            cal(cur + 2, ret * num);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> s;
    cal(0, 0);
    cout << mx;
}
