class Solution 
{
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        long long ans=0,n=nums.size();
        for(int i=n-2; i >= 0; i--)
        {
            if(nums[i]>nums[i+1])
            {
                int k = ceil((double)(nums[i])/nums[i+1]);
                ans += k-1;
                nums[i] /= k;
            }
        }
        return ans;
    }
};