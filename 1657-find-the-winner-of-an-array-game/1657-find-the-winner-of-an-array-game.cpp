class Solution 
{
public:
    int getWinner(vector<int>& nums, int k) 
    {
        if (k == 1)     return max(nums[0], nums[1]);
        int ans = nums[0], cur = 0, n = nums.size();

        for (int i = 1; i < nums.size(); i++) 
        {
            if (ans <= nums[i])     ans = nums[i], cur = 1;
            else                    cur++;
            if (k == cur)   return ans;
        }

        return ans;
    }
};