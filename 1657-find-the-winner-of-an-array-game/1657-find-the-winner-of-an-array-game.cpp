class Solution 
{
public:
    int getWinner(vector<int>& nums, int k) 
    {
        int ans = nums[0];
        for (int i = 1,j = 0; i < nums.size(); i++) 
        {
            if (ans <= nums[i])     ans = nums[i], j = 1;
            else                    j++;
            if (k == j)   return ans;
        }
        return ans;
    }
};