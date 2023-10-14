class Solution 
{
public:
    int solve(vector<int>& a, vector<int>& b, int i, int j,vector<vector<int>> &dp)
    {
        if(j <= 0)   return 0;
        if(i >= a.size())    return 1e9;   
        if(dp[i][j] != -1)   return dp[i][j];
        else 
        {
            int notTake = solve(a, b, i+1, j,dp);
            int take = a[i] + solve(a, b, i+1, j -  b[i] -1,dp); 
            return dp[i][j] = min(notTake, take);      
        }
    }
    int paintWalls(vector<int>& a, vector<int>& b) 
    {
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return solve(a, b, 0, b.size(),dp);
    }
};