class Solution {
public:
    int search(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int l = 0,h=n-1;
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(nums[m] == k) return m;
            else if(nums[l] <= nums[m])
            {
                if(nums[l] <= k && nums[m]>=k) h = m-1;
                else l  = m+1;
            }
            else 
            {
                if(nums[m] <= k && nums[h] >= k) l = m+1;
                else h = m-1;
            }
        }
        return -1;
    }
};