class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int i = k, j = k;
        int mini = nums[k];
        int ans = mini;
        while (i > 0 || j < nums.size() - 1) 
        {
            if (i == 0 || (j < nums.size() - 1 && nums[j + 1] > nums[i - 1]))    j++;
            else    i--;
            mini = min(mini, min(nums[i], nums[j]));
            ans = max(ans, mini * (j - i + 1));
        }
        return ans;
    }
};