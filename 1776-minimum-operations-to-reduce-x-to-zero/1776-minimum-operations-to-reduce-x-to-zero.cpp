class Solution 
{
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int k = 0, n = nums.size();
        for (auto &i : nums) k += i;
        k -= x;
        if (k == 0) return n;
        int ans = 0, sum = 0, j = 0;
        for (int i = 0; i < n; i++) 
        {
            sum += nums[i];
            while (j <= i && sum > k)   sum -= nums[j++];
            if (sum == k) ans = max(ans, i - j + 1);
        }
        if(!ans) return -1;
        return n-ans;
    }
};