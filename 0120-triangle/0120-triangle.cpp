class Solution 
{
public:
    int solve(int i,int j,int m,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i == m - 1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d  = triangle[i][j] + solve(i+1,j  ,m,triangle,dp);
        int dg = triangle[i][j] + solve(i+1,j+1,m,triangle,dp);
        return dp[i][j] = min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,triangle,dp);
    }
};