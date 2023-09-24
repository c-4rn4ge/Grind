class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int i=0,j=nums.size()-1,k=0;
        while(k<=j)
        {
            if(!nums[k])    
                swap(nums[k++],nums[i++]);
            else if(nums[k]==1)   
                k++;
            else if(nums[k]==2) 
                swap(nums[k],nums[j--]);
        }
    }
};