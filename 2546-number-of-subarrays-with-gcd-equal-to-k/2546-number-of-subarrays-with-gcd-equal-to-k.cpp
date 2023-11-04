class Solution 
{
public:
    int subarrayGCD(vector<int>& nums, int k) 
    {
        int ans = 0, n = nums.size();
        if(k == 1)
        {

        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == k) ans++;
            int x = nums[i];
            for(int j = i + 1; j < n; j++)
            {
                if(nums[j] % k != 0) break;
                x = __gcd(x, nums[j]);
                if(x == k)  ans++;
            }
        }
        return ans;
    }
};