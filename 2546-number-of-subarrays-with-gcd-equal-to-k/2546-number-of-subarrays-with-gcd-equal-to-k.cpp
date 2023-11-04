class Solution 
{
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {
        int ans = 0, n = nums.size(), x;
        for(int i = 0; i < n ; i++)
        {
            if((x = nums[i]) == k) ans++;
            for(int j = i + 1; j < n; j++)  if((x = __gcd(x, nums[j])) == k)  ans++;
        }
        return ans;
    }
};