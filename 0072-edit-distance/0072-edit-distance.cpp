class Solution 
{
public:
    int minDistance(string s, string t) 
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i = 0 ; i <= m ; i++) dp[0][i] = i;
        for(int i = 1 ; i <= n ; i++) dp[i][0] = i;

        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1; j <= m ; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    int rep = dp[i-1][j-1];
                    int del = dp[i-1][j];
                    int ins = dp[i][j-1];
                    dp[i][j] = 1 + min(rep , min(del , ins));
                }
            }
        }
        return dp[n][m];
    }
};