class Solution 
{
public:
    vector<int> findArray(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) 
        {
            ans[i] = nums[i] ^ nums[i-1];
        }
        return ans;
    }
};