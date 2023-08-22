class Solution {
public:
    int dp[102][102];
    int solve(vector<vector<int>>&arr,int m,int i,int j)
    {   
        if(i>m) return 0;
        if(j>m || j<0)  return INT_MAX;
        if(dp[i][j]!=INT_MAX)   return dp[i][j];
        return dp[i][j]=arr[i][j]+min(solve(arr,m,i+1,j-1),min(solve(arr,m,i+1,j),solve(arr,m,i+1,j+1)));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
       int ans=INT_MAX;
       int m=matrix.size()-1; 
       for(int i=0;i<=m;i++)    for(int j=0;j<=m;j++)   dp[i][j]=INT_MAX;
       for(int i=0;i<=m;i++)
       {
        ans=min(ans,solve(matrix,m,0,i));
       }
       return ans;
    }
};