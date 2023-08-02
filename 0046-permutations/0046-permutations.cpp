class Solution {
public:
    void solve(int i, int n,vector<int> &nums, vector<vector<int>> &ans)
    {
        if(i==n) ans.push_back(nums);
        else
        {
            for(int j = i; j<n ;j++)
            {
                swap(nums[i],nums[j]);
                solve(i+1,n,nums,ans);
                swap(nums[i],nums[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        solve(0,nums.size(),nums,ans);
        return ans;
    }
};