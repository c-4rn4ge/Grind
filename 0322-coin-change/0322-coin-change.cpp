class Solution 
{
public:
    int solve(int n , int k , vector<int> &nums,vector<vector<int>> &dp)
    {
        if(k == 0) return 0;
        if(n == 0)
        {
            if( k >= nums[0] && k % nums[0] == 0) return k / nums[0];
            else return 1e9;
        }
        if(dp[n][k] != -1) return dp[n][k];
        int take = 1e9, notTake = 1e9;
        notTake = solve(n-1,k,nums,dp);
        if(nums[n] <= k) take = 1 + solve(n,k-nums[n],nums,dp);
        return dp[n][k] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>> dp(coins.size() , vector<int>(amount+1,-1));
        int ans = solve(coins.size()-1,amount,coins,dp);
        return (ans>=1e9) ? -1 : ans;
    }
};
