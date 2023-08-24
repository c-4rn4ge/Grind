class Solution 
{
public:
    int solve(int n , int k , vector<int> &nums,vector<vector<int>> &dp)
    {
        if(k == 0) return 0;
        if(n == 0)
        {
            if(k % nums[0] == 0) return k / nums[0];
            else return 1e9;
        }
        if(dp[n][k] != -1) return dp[n][k];
        int take = 1e9, notTake = 1e9;
        notTake = solve(n-1,k,nums,dp);
        if(nums[n] <= k) take = 1 + solve(n,k-nums[n],nums,dp);
        return dp[n][k] = min(take,notTake);
    }
    int coinChange(vector<int>& nums, int amount) 
    {
        if(amount == 0) return 0;
        vector<vector<int>> dp(nums.size() , vector<int>(amount+1,0));
        int n = nums.size();
        for(int i = 0 ; i <= amount ; i++)
        {
            if(i % nums[0] ==0) dp[0][i] = i / nums[0];
            else dp[0][i] = 1e9;
        }
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 1 ; j <= amount ; j++)
            {
                int take = 1e9, notTake = 1e9;
                notTake = dp[i-1][j];
                if(nums[i] <= j) take = 1 + dp[i][j-nums[i]];
                dp[i][j] = min(take,notTake);
            }
        }
        int ans = dp[n-1][amount];
        return (ans>=1e9) ? -1 : ans;
    }
};
