class Solution {
public:
    bool solve(vector<int> &arr, int i, vector<int> &dp)
    {
        if (i == arr.size() - 1)  return true;
        if (arr[i] == 0)          return 0;
        if (dp[i] != -1)          return dp[i];
        for (int j = 1; j <= arr[i]; j++)
        {
            if (j < arr.size() && solve(arr, j + i, dp))   return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int> &arr)
    {
        vector<int> dp(arr.size(), -1);
        return solve(arr, 0, dp);
    }
};