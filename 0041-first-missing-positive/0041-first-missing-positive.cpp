class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {            
        int n = nums.size();
        for(int i = 0; i < n; i++) 
        {
            if(nums[i] <= n && nums[i] > 0 && nums[i] != nums[nums[i]-1])   
                swap(nums[i],nums[nums[i] - 1]),i--;
        }
        for(int j = 0; j < n; j++) 
        {
            if(nums[j] != j + 1)    return j + 1;
        }
        return n + 1;
    }
};