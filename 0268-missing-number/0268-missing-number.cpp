class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int a = 0, sum =0;
        n = (n*(n+1))/2;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]==0) a=1;
            sum += nums[i];
        } 
        if(a==0) return 0;
        return n - sum;
    }
};