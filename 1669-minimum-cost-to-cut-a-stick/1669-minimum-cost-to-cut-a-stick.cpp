class Solution 
{
public:
    int minCost(int c, vector<int>& nums) 
    {
        nums.push_back(0);
        nums.push_back(c);
        sort(begin(nums), end(nums));
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, n));

        for (int i = 0; i + 1 < n; i++) dp[i][i + 1] = 0;
        for (int i = 0; i + 2 < n; i++) dp[i][i + 2] = nums[i + 2] - nums[i];

        for (int i = n - 4; i >= 0; i--) 
        {
            for (int j = i + 3; j < n; j++) 
            {
                int val = 1e9;
                for (int k = i + 1; k < j; k++) 
                {
                    val = min(val, dp[i][k] + dp[k][j]);
                }
                dp[i][j] = val + nums[j] - nums[i];
            }
        }
        return dp[0][n - 1];
    }
};