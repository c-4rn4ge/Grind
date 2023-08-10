class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        int l = 0,i,ans=0;
        for(i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            while(nums[i] == 0 && m[0] > k)
            {
                m[nums[l++]]--;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};