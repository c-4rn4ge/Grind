class Solution 
{
public:
    bool subsetSumToK(int n, int k, vector < int > & arr) 
    {
        vector < vector < bool >> dp(n, vector < bool > (k + 1));
        for(int i = 0 ; i < n ; i++)    dp[i][0] = true;
        for(int i = 0 ; i <= k ; i++) if(arr[0] == i) dp[0][i] = true;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 1; j <= k ; j++)
            {
                if(i>0)dp[i][j] = dp[i-1][j];
                if(j - arr[i] >= 0 && i>0) dp[i][j] = dp[i][j] || dp[i-1][j-arr[i]];
            }
        }
        return dp[n-1][k];
    }
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(auto &i : nums) sum += i;
        if(sum & 1) return false;
        return subsetSumToK(nums.size(),sum/2,nums);
    }
};