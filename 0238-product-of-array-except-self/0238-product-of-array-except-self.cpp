class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size(),pre=1,suf=1;
        vector<int> ans(n,1);
        for(int i = 0 ; i < n; i++) 
        {
            ans[i] = pre;
            pre = pre * nums[i];
        }
        for(int i = n-1 ; i >= 0 ; i--)
        {
            ans[i] *= suf;
            suf = suf * nums[i];
        }
        return ans;
    }
};