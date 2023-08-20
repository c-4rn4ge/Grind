class Solution {
public:
    int solve(int i,vector<int> c,int a,vector<vector<int>>&dp)
    {
        if (a==0)           return 0;
        if (i<0 || a<0)     return 1e6;
        if (dp[a][i]!=-1)   return dp[a][i];
        int inc,nc;
        nc = solve(i-1,c,a,dp);
        inc = 1e6;
        if(c[i]<=a) inc = 1 + solve(i,c,a-c[i],dp);
        return dp[a][i]=min(inc,nc);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        sort (coins.begin(),coins.end());
        vector<vector<int>> dp(amount+1,vector<int>(coins.size(),-1));
        int ans=solve(coins.size()-1,coins,amount,dp);
        return (ans>=1e6)?-1:ans;
    }
};