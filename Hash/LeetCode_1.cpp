class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
    vector<int> ans;
    map<int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]] = i;
      
    }
   for (int i = 0; i < nums.size(); i++) {
        int a = target - nums[i];
     if(mp.find(a) != mp.end() && mp[a] != i)
        {
            ans.push_back(mp[a]);
            ans.push_back(i);
            return ans;
        }
   }
    return ans;
    }
};
