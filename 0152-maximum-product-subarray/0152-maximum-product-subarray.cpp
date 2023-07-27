class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int prod1=nums[0],prod2=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0) swap(prod1,prod2);
            prod1 = max(prod1*nums[i],nums[i]);
            prod2 = min(prod2*nums[i],nums[i]);
            ans = max(ans,prod1);
        }
        return ans;
    }
};