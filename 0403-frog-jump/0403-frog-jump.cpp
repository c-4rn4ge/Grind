class Solution 
{
private:
    // bool solve(vector<int>& nums, int n,int i, int j,vector<vector<int>> &dp)
    // {
    //     if(i >= n)  return false;
    //     if(i == n-1)    return true;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     for(int t = -1 ; t<=1 ;t++)
    //     {
    //         int jump = j + t;
    //         for(int j=i+1; j<n; j++)
    //         {
    //             if(nums[i] + jump == nums[j])
    //             {
    //                 if(solve(nums, n , j, jump,dp))    return dp[i][j] = true;
    //             }
    //         }
    //     }
    //     return dp[i][j] = false;
    // }
public:
    bool canCross(vector<int>& stones) 
    {
        int n = stones.size();
        if(stones[1]>1)   return false;
        if(n==2)        return (stones[1]-stones[0]==1);
        vector<vector<bool>> dp(n, vector<bool> (n+1, false));
        dp[0][1] = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int d = stones[i] - stones[j];
                if(d > n || dp[j][d] == false)    continue;
                if(i == n - 1)                  return true;
                dp[i][d] = true;
                if(d - 1 >= 0) dp[i][d - 1] = true;
                if(d + 1 <= n) dp[i][d + 1] = true;
            }
        }
        return false;
    }
};
