class Solution 
{
private:
    int solve(int i, vector<int> &dp)
    {
        if(i==0) return 1;
        else if(i < 0) return 0;
        if(dp[i] != -1 ) return dp[i];
        return dp[i] = solve(i-1,dp) + solve(i-2,dp);
    }
public:
    int climbStairs(int n) 
    {
        vector<int> dp(n+1,-1);
        return solve(n,dp);        
    }
};