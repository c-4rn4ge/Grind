class Solution 
{
public:
    int solve(vector<int>& nums, int k)
    {
        std::ios_base::sync_with_stdio(0), std::cin.tie(0);
        unordered_map<int,int> mp;
        int maxCount = 0,left = 0,right = 0,n = nums.size();
        while(right < n)
        {
            mp[nums[right]]++;
            while(mp.size() > k)
            {
                mp[nums[left]]--;
                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            } 
            maxCount += right - left + 1;
            right++;
        }
        return maxCount;        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        std::ios_base::sync_with_stdio(0), std::cin.tie(0);
        return solve(nums,k) - solve(nums,k-1);
    }
};