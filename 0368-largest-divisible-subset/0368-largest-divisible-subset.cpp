class Solution 
{
public:
    vector<int> solve(vector<int>& arr) 
    {
        int n = arr.size();
        int maxi = 0,ind = -1;
        vector<int> dp(n,1),hash(n);
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) hash[i] = i; 
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < i; j++)
            {
                if(arr[i]%arr[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                ind = i;
            }
        }
        for(int i = 0 ; i < maxi ; i++)
        {
            ans.push_back(arr[ind]);
            ind = hash[ind];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        return solve(nums);
    }   
};