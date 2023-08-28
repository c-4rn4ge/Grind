class Solution 
{
public:
    bool isGood(vector<int>& nums) 
    {
        int maxi = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) maxi = max(maxi,nums[i]);
        if(n < maxi+1) return false;
        vector<int> hash(maxi+1,0);
        for(auto i:nums)    hash[i]++;
        if(hash[maxi]!=2) return false;
        for(int i=1;i<maxi;i++)
        {
            if(hash[i]!=1) return false;
        }
        return true;
    }
};