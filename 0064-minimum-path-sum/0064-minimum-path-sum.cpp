class Solution 
{
public:
    int solve(int m , int n , vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n < 0) return 201;
        if(dp[m][n] != -1) return dp[m][n];
        int up   = solve(m-1,n,grid,dp) + grid[m][n]; 
        int left = solve(m,n-1,grid,dp) + grid[m][n];
        return dp[m][n]= min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // return solve(m-1,n-1,grid,dp);
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