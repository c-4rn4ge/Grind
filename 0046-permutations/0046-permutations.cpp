class Solution {
public:
    void getPermutation(vector<int>& nums,vector<vector<int>> &ans,int ind,int n)
    {
        if(ind==n)
            ans.push_back(nums);
        else
            for(int i=ind;i<n;i++)
            {
                swap(nums[ind],nums[i]);
                getPermutation(nums,ans,ind+1,n);
                swap(nums[ind],nums[i]);
            }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;int n= nums.size();
        getPermutation(nums,ans,0,n);
        return ans;
    }
};