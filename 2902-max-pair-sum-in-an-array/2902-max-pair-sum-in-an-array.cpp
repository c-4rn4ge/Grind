class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        int ans = -1, mp[10] = {};
        for (auto n : nums) 
        {
            int d = 0;
            for (int v = n; v; v /= 10) d = max(d, v % 10);
            if (mp[d])  ans = max(ans, mp[d] + n);
            mp[d] = max(mp[d], n);
        }
        return ans;
    }
};