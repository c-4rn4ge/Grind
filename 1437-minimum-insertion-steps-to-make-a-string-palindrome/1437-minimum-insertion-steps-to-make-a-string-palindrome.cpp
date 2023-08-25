class Solution 
{
public:
    int minInsertions(string s) 
    {
        int n = s.size();
        int dp[n][n];
        for (int i = 0; i < n; i++) 
        {
            dp[i][i] = 0;
            if (i > 0)  dp[i][i-1] = 0;
        }
        for (int i = n - 2; i >= 0; i--) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (s[i] == s[j])   dp[i][j] = dp[i + 1][j - 1];
                else                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
        return dp[0][n-1];
    }
};