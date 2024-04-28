#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arrOne [20][20] = {};
int arrTwo [20][20] = {};

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++)
    {
        int temp=n-1;
        while(temp>=0)
        {
            
            arrOne[i][temp] = arr1[i] % 2; 
            arr1[i] /= 2;
            //cout << arrOne[i][n] << '\n';
            arrTwo[i][temp] = arr2[i] % 2;
            arr2[i] /= 2;
            temp--;
        }
        
    }
    
    for(int i=0; i<n; i++)
    {
        string s= "";
        for(int j=0; j<n; j++)
        {
            //cout << arrOne[i][j] << '\n';
            if(arrOne[i][j] == 1 || arrTwo[i][j] == 1)
            {
                
                s += '#';
            }
            else 
            {
                s += " ";
            }
        }
        answer.push_back(s);
    }
    return answer;
    
}