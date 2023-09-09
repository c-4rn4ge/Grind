class Solution 
{
public:
    int solve(vector<int>&nums, int k, vector<int>& dp)
    {
        if(k < 0) return 0;
        if(k == 0)return 1;
        if(dp[k]!=-1) return dp[k];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
           ans += solve(nums, k-nums[i], dp);
        }
        return dp[k] = ans;
    }
    int combinationSum4(vector<int>& nums, int k) 
    {
        vector<int> dp(k+1, -1);
        return solve(nums, k, dp);
    }
};