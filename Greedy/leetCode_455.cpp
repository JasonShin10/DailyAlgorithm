class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        vector<int> ans;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        priority_queue<int> pq;
        int j =0;
        for(int i=0; i<g.size(); i++)
        {
            while(j<s.size())
            {
                if(g[i] <= s[j])
                {
                    cout << s[j] << "\n";
                    pq.push(s[j]);
                    j++;
                    break;
                }
                else
                {
                    j++;
                }
            }
            if(pq.size())
            {
            ans.push_back(pq.top());
            pq.pop();
            }

        }
        return ans.size();
    }
};
