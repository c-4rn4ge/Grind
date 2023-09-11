class Solution 
{
public:
    int solve(int i, vector<int> &nums, vector<int> &dp)
    {
        int j = i + nums[i];
        if (j >= nums.size() - 1)   return 0;
        if (dp[i] != -1)    return dp[i];
        int mini = 1e7;
        for (int k = i + 1; k <= j; k++)
        {
            int steps = 1 + solve(k, nums, dp);
            mini = min(mini, steps);
        }
        return dp[i] = mini;
    }
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1) return 0;
        vector<int> dp(n, -1);
        return solve(0, nums, dp) + 1;
    }
};