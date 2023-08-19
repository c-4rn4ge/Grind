class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size(),ans=0;
        vector<int> t;    
        t.push_back(nums[0]);
        for(int i = 1; i < n; i++)
        {
            auto l = lower_bound(t.begin(),t.end(),nums[i]);
            auto h = upper_bound(t.begin(),t.end(),nums[i]);
            if(h == t.end())
            {
                t.push_back(nums[i]);
            }
            else
            {
                int ind = h - t.begin();
                t[ind] = min(t[ind],nums[i]);
                ans++;
            }
        }
        return ans;
    }
};