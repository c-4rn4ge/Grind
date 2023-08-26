class Solution 
{
public:
    int lengthOfLIS(vector<int>& arr) 
    {
        int n = arr.size();
        int maxi = 1;
        vector<int> dp(n+1,1);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < i; j++)
            {
                if(arr[j] < arr[i] && 1 + dp[j] > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(dp[i],maxi);
        }
        return maxi;
    }
};