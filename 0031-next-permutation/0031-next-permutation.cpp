class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i ,bp = 0,n= nums.size();
        for(i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i]) {bp = i;break;}
        }
        if(bp==0) reverse(nums.begin(),nums.end());
        else
        {
            int t = nums[bp-1];
            for(i=n-1;i>0;i--)
            {
                if(nums[i] > t) break;
            }
            swap(nums[bp-1],nums[i]);
            reverse(nums.begin()+bp , nums.end()); 
        }
    }
};