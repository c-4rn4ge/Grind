class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
       int n=nums.size(),i,count=1,ans=nums[0];
        for(i=1;i<n;i++)
        {
            if(count==0) ans = nums[i],count=1;
            else if(ans != nums[i]) count--;
            else if(ans==nums[i]) count++;
            
        }
        return ans;
    }
};