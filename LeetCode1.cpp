class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(), v.end());
        int l = 0;
        int r = nums.size()-1;
        while(l<r)
        {
            int m = v[l].first+v[r].first;
            if(m == target)
            {
                ans.push_back(v[l].second);
                ans.push_back(v[r].second);
                break;
            }
            else if(m > target)
            {
                r--;
            }
            else if(m < target)
            {
                l++;
            }
        }
        return ans;
    }
};
