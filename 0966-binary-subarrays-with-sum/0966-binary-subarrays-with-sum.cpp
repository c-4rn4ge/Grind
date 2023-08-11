class Solution 
{
public:
    int helper(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;
        int l=0,r=0,k=0,sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>goal) sum-=nums[l++];
            k+=r-l+1;
            r++;
        }
        cout<<k<<endl;
        return k;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};