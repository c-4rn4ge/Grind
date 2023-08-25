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
        vector<vector<int>> dp(text1.length()+1,vector<int> (text2.length()+1,0));
        for(int i = 1; i <= text1.length(); i++)
        {
            for(int j = 1; j <= text2.length(); j++)
            {
                if(text1[i-1]==text2[j-1])  
                {
                    dp[i][j] =  1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[text1.length()][text2.length()];
    }
};