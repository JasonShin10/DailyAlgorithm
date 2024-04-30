#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<char> st;
int solution(string s) {
    int answer = 0;
    string temp = s;
    int n =0;
    bool flag = true;
    while(n < s.size()-1)
    {
        n++;
        
      for(int i=0; i<temp.size(); i++)
      {
        if(temp[i] == '(' || temp[i] == '{' || temp[i] == '[')
        {
            st.push(temp[i]);
        }
        else if(temp[i] == ')')
        {
            if(st.empty() || st.top() != '(')
            {
                flag = false;
                break;
            }
            else
            {
                st.pop();
            }
        }
          else if(temp[i] == '}')
        {
            if(st.empty() || st.top() != '{')
            {
                flag = false;
                break;
            }
            else
            {
                
                st.pop();
            }
        }
            else if(temp[i] == ']')
        {
            if(st.empty() || st.top() != '[')
            {
                 flag = false;
                break;
            }
            else
            {
               
                st.pop();
            }
        }
      }
        if(st.empty() && flag == true)
        {
            answer++;
        }
        else
        {
            flag = true;
            while(!st.empty())
            {
                st.pop();
            }
        }
       temp = "";
        temp = s+ s[0];
        temp.erase(0,1);
        s = temp;
    }
    return answer;
}
