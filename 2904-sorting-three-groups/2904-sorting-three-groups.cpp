class Solution
{
public:
    int solve(int i, vector<int> &nums, int n, int j, vector<vector<int>> &dp)
    {
        if (i == n)     return 0;
        if (dp[i][j] != -1)     return dp[i][j];
        int p = INT_MAX;
        int nt = INT_MAX;
        for (int k = 1; k <= 3; k++)
        {
            if (k != nums[i])
            {
                if (j <= k)     p = min(p, 1 + solve(i + 1, nums, n, k, dp));
            }
        }
        if (j <= nums[i])
        {
            nt = solve(i + 1, nums, n, nums[i], dp);
        }
        return dp[i][j] = min(nt, p);
    }
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(0, nums, n, 0, dp);
    }
};