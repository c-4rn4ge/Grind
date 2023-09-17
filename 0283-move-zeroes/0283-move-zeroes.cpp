class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int l,r;
        l = r = 0;
        while(r<nums.size() && l < nums.size())
        {
            if(nums[r] == 0) r++;
            else if(nums[l] == 0) swap(nums[l++],nums[r]);
            else l++,r++;
        }
    }
};