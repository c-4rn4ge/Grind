class Solution {
public:
    int solve(int i , int j , string &s , string &t, vector<vector<int>> &dp)
    {
        if(!j) return !i;
        if(!i)
        {
            for(int a = 1; a <= j; a++) 
            {
                if(t[a-1] != '*') return 0;
            }
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == t[j-1] || t[j-1] == '?')
        {
            return dp[i][j] = solve(i-1,j-1,s,t,dp);
        }
        else if(t[j-1] == '*')
        {
            return dp[i][j] = solve(i,j-1,s,t,dp) || solve(i-1,j,s,t,dp);
        }
        return 0;
    }
    bool isMatch(string s, string p) 
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,p,dp);
    }
};