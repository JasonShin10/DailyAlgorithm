#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void findPelindrome(string s)
{
    for (int i = 0; i <= s.size()/2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
        {
            cout << "no" << "\n";
            return;
        }
    }
    cout << "yes" << "\n";
    return;
}

int main() {
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        string s;
        s = to_string(n);
        findPelindrome(s);
    }
    return 0;
}
