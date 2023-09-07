class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length(),row =0,col=0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)    dp[i][i] = 1;
        for (int i = 0; i < n - 1; i++) 
        {
            if (s[i] == s[i + 1])   dp[i][i + 1] = 1,row = i,col = i + 1;
        }
        for (int i = 2; i < n; i++) 
        {
            for (int j = 0; j < n - i; j++) 
            {
                if (s[j] == s[j + i] && dp[j + 1][j + i - 1]) 
                {
                    dp[j][j + i] = 1;
                    row = j;
                    col = j + i;
                }
            }
        }        
        return s.substr(row, col - row + 1);
    }
};