class Solution {
public:
    int maxProfit(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = 0 ; j <= 1; j++)
            {
                if(j==1)
                {   
                    dp[i][j] = max(-nums[i] + dp[i+1][0] , dp[i+1][1]);
                }
                else
                {
                    dp[i][j] = max(nums[i] + dp[i+2][1] , dp[i+1][0]);
                }
            }
        }

        return dp[0][1];    
    }
};