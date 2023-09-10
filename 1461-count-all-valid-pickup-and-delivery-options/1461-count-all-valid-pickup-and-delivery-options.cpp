class Solution 
{
public:
    long long int mod = 1000000007;
    long long int solve(int n,int p,int d,vector<vector<long long int>> &dp)
    {
        if(d>p || d>n || p>n)   return 0;
        if(p==n && d==n)        return 1;
        if(dp[p][d]!=-1)        return dp[p][d];
        int pick = ((n-p) * solve(n,p+1,d,dp)) % mod;
        int del =  ((p-d) * solve(n,p,d+1,dp)) % mod;
        return dp[p][d] = (pick + del ) % mod;
    }
    long long int countOrders(int n) 
    {
        vector<vector<long long int>>dp(501,vector<long long int>(501,-1));
        return solve(n,0,0,dp);
    }
};