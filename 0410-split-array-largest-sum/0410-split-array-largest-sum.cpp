class Solution {
public:
    int systum(vector<int> &nums, int p) 
    {
        int n = nums.size(),s = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++) 
        {
            if (sum + nums[i] <= p) sum += nums[i];
            else  sum = nums[i],s++;

        }
        return s;
    }

    int solve(vector<int>& nums, int n, int m) 
    {
        if (m > n) return -1;
        int l = *max_element(nums.begin(), nums.end()), h = accumulate(nums.begin(), nums.end(), 0);
        while (l <= h) 
        {
            int mi = (l + h) / 2;
            if (systum(nums, mi) > m) l = mi + 1;
            else h = mi - 1;
        }
        return l;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        return solve(nums,nums.size(),k);
    }
};