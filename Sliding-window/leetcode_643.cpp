class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double sum=0;
        for(int i=0; i<k;i++)
        {
            sum += nums[i];
        }
        double mx = sum;
        for(int i=k; i<nums.size(); i++)
        {
            sum += nums[i] - nums[i-k];
            if(mx < sum)
            {
                mx = sum;
            }
        }
        double ans = mx/k;
        return ans;
    }
};
