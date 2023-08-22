class Solution 
{
public:
    int solve(int n,vector<int> & nums, vector<int> &dp)
    {
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int left  = solve(n-2,nums,dp) + nums[n]; 
        int right = solve(n-1,nums,dp); 
        return dp[n] = max(left,right);
    }
    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int n = nums.size();
        for(int i = 1; i < n ; i++)
        {
            int left = 0,right = 0;
            (i > 1) ? left  = dp[i-2] + nums[i] : left = nums[i];
            right = dp[i-1];
            dp[i] = max(left,right);
        }
        return dp[n-1];
    }
};