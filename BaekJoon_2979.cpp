#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int>> timeArr;
    int A, B, C;
    cin >> A >> B >> C;
    int sum = 0;
    int arr[100] = {};
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        timeArr.push_back({ a,b });
        for (int j = a; j < b; j++)
        {
            arr[j]++;
        }
    }
    for (int i = 1; i <= 100; i++)
    {
        if (arr[i] == 1)
        {
            sum += arr[i] * A;
        }
        else if (arr[i] == 2)
        {
            sum += arr[i] * B;
        }
        else if (arr[i] == 3)
        {
            sum += arr[i] * C;
        }
     
    }

    cout << sum;
    
}
