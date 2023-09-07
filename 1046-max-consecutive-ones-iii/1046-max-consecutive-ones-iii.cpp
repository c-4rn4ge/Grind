class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int r = 0,l,ans=0,z=0,o=0;
        for(l=0;l<nums.size();l++)
        {
            (nums[l]) ? o++ : z++;
            while(z > k) (nums[r]) ? o--: z--,r++;
            ans = max(ans,l-r+1);
        }
        return ans;
    }
};