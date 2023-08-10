class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        int sum=0,ans=0;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            m[sum]++;
        }sum=0;
        for(int i = 0;i<nums.size();i++)
        {
            if(m.find(k+sum) != m.end())    ans += m[k+sum];
            sum += nums[i];
            m[sum]--;
        }
        return ans;
    }
};