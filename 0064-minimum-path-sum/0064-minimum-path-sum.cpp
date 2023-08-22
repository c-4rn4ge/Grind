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
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};