class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int r = 0,l=0,ans=0,z=0,o=0,n=nums.size();
        while(l<n)
        {
            (nums[l]) ? o++ : z++;
            while(z > k) (nums[r]) ? o--: z--,r++;
            ans = max(ans,(l++)-r+1);
        }
        return ans;
    }
};