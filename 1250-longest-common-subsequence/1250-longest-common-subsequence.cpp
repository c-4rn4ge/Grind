class Solution {
public:
    int solve(int i, int j, string &s,string &t,vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==t[j])  return 1 + solve(i-1,j-1,s,t,dp);
        return dp[i][j] = max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
        return solve(text1.length()-1,text2.length()-1,text1,text2,dp);    
    }
};