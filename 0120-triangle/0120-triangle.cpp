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
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++)    dp[m-1][i] = triangle[m-1][i];
        for(int i = m-2 ; i >= 0 ; i--)
        {
            for(int j = i ; j >= 0 ; j--)
            {
                int d  = triangle[i][j] + dp[i+1][j] ;
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
};