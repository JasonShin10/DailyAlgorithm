#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    return a < b;
}
int main() {
    int N;
    vector<string> arr;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()),arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
