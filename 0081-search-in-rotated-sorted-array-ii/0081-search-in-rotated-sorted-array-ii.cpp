class Solution {
public:
    bool search(vector<int>& nums, int k) 
    {
        int n  = nums.size();
        int l = 0,h = n-1;
        while(l<=h)
        {
            if(l>= n && h<0) return false;
            int m = l + (h-l)/2;
            if(nums[l] == k || nums[m] == k || nums[h] == k) return true;
            else if(nums[l] == nums[h]) l++,h--;
            else if(nums[l] <= nums[m])
            {
                if(nums[l] < k && nums[m] > k) h = m-1;
                else l = m+1;
            }
            else
            {
                if(nums[m] < k && nums[h] > k) l = m+1;
                else h = m-1;
            }
        }
        return false;
    }
};