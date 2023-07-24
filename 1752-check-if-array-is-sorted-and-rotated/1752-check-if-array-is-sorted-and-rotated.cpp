class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int tp = 0,i;
        for(i=0;i<nums.size()-1;i++) if(nums[i] > nums[i+1]) tp++;
        if(tp == 0) return true;
        if(tp > 1) return false;
        if(nums[nums.size()-1] <= nums[0]) return true;
        return false;
    }
};