class Solution 
{
public:
    bool solve(int i,int k,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==nums.size()-1)   return true;
        bool a = false;
        if(dp[i][k]!=-1)return dp[i][k];
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]>(nums[i]+k+1))break;
            else if(nums[j]==(nums[i]+k-1))   a |= solve(j,k-1,nums,dp);
            else if(nums[j]==(nums[i]+k))     a |= solve(j,k,nums,dp);
            else if(nums[j]==(nums[i]+k+1))   a |= solve(j,k+1,nums,dp);
        }
        return dp[i][k]= a;
    }

    bool canCross(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n+2,vector<int>(4000,-1));
        return solve(0,0,nums,dp);
    }
};