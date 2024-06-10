#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<char> v;
char arr[8] = {'A','C','F','J','M','N','R','T'};
bool visited[8] = {};
bool flag =false;
int cnt=0;
vector<string> ddata;

void combi()
{
    if(v.size() == 8)
    {
        
        for(int i=0; i<ddata.size(); i++)
        {
            
            auto a = find(v.begin(), v.end(), ddata[i][0]);
            auto b = find(v.begin(), v.end(), ddata[i][2]);
            
            int d = abs((a - v.begin())-(b-v.begin()))-1;
                 
            if(ddata[i][3] == '=')
            {
               if(d != ddata[i][4] -'0')
               {
                   flag = true;
                   break;
               }
            }
            else if(ddata[i][3] == '<')
            {
                if(d >= ddata[i][4] -'0')
                {
                    flag = true;
                    break;
                }
            }
            else if(ddata[i][3] == '>')
            {
                if(d <= ddata[i][4]-'0')
                {
                    flag = true;
                    break;
                }
            }
                   
        }
        if(flag != true)
        {
           cnt++;
        }
        flag = false;
        return;
    }
    
    for(int i=0; i<8; i++)
    {
       if (!visited[i]) {
            visited[i] = true;
            v.push_back(arr[i]);
            combi();
            v.pop_back();
            visited[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    ddata = data;
    int answer = 0;
    cnt =0;
    combi();
    answer = cnt;
    return answer;
}
