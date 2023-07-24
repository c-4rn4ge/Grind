class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int i=0 ,j=1,n = nums.size();
        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]!=0) i++,j++;
            else if(nums[j]==0) j++;
            else swap(nums[i++],nums[j]);
        }
    }
};