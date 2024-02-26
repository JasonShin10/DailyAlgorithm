class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> ms;
        for(int i=0; i<logs.size(); i++)
        {
            if(logs[i] == "./")
            {
                continue;
            }
            else if(logs[i] == "../")
            {
                if(!ms.empty())
                {
                ms.pop();
                }
            }
            else
            {
                ms.push(logs[i]);
            }
        }

        return ms.size();
    }
};
