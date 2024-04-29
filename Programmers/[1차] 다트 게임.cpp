#include <string>
#include <cctype>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num =0;
    vector<int> v;
    for(int i=0; i<dartResult.size(); i++)
    {
        
        if(isdigit(dartResult[i]))
        {
            
            if(isdigit(dartResult[i+1]))
            {
                num = stoi(dartResult.substr(i,2));
                i++;
                cout << num;
                continue;
            }
            num = dartResult[i]-'0';
        }
        else if(dartResult[i] == 'S')
        {
            num = pow(num,1);
            v.push_back(num);
            num=0;
            
        }
        else if(dartResult[i] == 'D')
        {
            num = pow(num,2);
            v.push_back(num);
            num=0;
        }
        else if(dartResult[i] == 'T')
        {
            num = pow(num,3);
            v.push_back(num);
            num =0;
        }
        else if(dartResult[i] == '*')
        {
            v[v.size()-1] = v[v.size()-1] * 2;
            if(v.size() > 1)
            {
                v[v.size()-2] = v[v.size()-2] * 2;
            }
        }
        else if(dartResult[i] == '#')
        {
            if(v[v.size()-1]>0)
            {
                v[v.size()-1] = -v[v.size()-1];
            }
        }
    }
    
    for(int i=0; i<v.size(); i++)
    {
        answer += v[i];
    }
    return answer;
}
