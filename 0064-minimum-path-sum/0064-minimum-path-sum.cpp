class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
                else
                {
                    int u = INT_MAX, l = INT_MAX;
                    if(i>0) u = dp[i-1][j] + grid[i][j];
                    if(j>0) l = dp[i][j-1] + grid[i][j];
                    dp[i][j] = min(u,l);
                }
            }
        }
        return dp[m-1][n-1];
    }
};