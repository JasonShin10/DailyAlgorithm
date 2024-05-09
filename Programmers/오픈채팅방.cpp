#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<string, string> mp;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> temp;

    for(int i=0; i<record.size(); i++)
    {
        string word;
        istringstream iss(record[i]);
        while(iss >> word)
        {
            temp.push_back(word);
        }
        if(temp[0] == "Enter" || temp[0] == "Change")
        {
            mp[temp[1]] = temp[2];
        }
        temp.clear();
    }
    
    for(int i=0; i<record.size(); i++)
    {
        string word;
        istringstream iss(record[i]);
        
            while(iss >> word)
            {
                temp.push_back(word);
            }
        if(temp[0] == "Enter")
        {
            string s = mp[temp[1]] + "님이 " + "들어왔습니다.";
            answer.push_back(s);
        }
        else if(temp[0] == "Leave")
        {
            string s = mp[temp[1]] + "님이 " + "나갔습니다.";
            answer.push_back(s);
        }
        temp.clear();
    }
    return answer;
}
