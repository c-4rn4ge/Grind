class Solution 
{
public:
    int solve(int m,int n , vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(m == 0 && n==0 && grid[m][n] == 0) return 1;
        if(m < 0 || n < 0 || grid[m][n] == 1) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int up   = solve(m-1,n,grid,dp);
        int left = solve(m,n-1,grid,dp);
        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};