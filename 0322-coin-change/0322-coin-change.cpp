class Solution
{
public:
    int coinChange(vector<int> &num, int k)
    {
        vector<int> dp(k + 1, num.size());
        dp[0] = 0;
        for (int j = 1; j <= k; j++)
        {
            int mini = INT_MAX;
            for (int i = 0; i < num.size(); i++)
            {
                if (j - num[i] >= 0)
                {
                    int ans = dp[j - num[i]];
                    if (ans != INT_MAX)
                        mini = min(mini, 1 + ans);
                }
            }
            dp[j] = mini;
        }
        return (dp[k] == INT_MAX) ? -1 : dp[k];
    }
};