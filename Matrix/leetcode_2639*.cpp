class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        int mx = -1e9;
        int r = grid.size();
        int c = grid[0].size();

        for(int i=0; i<c; i++)
        {
            int l;
            for(int j=0; j<r; j++)
            {
                l = to_string(grid[j][i]).size();
                cout << l;
                if(mx < l)
                {
                    mx = l;
                }
            }
            ans.push_back(mx);
            mx = 0;
        }
        return ans;
    }
};
