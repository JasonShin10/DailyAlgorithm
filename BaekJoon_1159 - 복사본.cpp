#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<char> arr;
    int A[26] = {};
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        A[s[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (A[i] > 4)
        {
            arr.push_back(i + 'a');
        }
    }
    sort(arr.begin(), arr.end());
    if (arr.empty())
    {
        cout << "PREDAJA";
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i];
        }
    }
}
