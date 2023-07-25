class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;int ans=0,i,n=nums.size(),sum=0;
        for(i=0;i<n;i++)
        {
            sum += nums[i];
            m[sum]++;
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            if(m.find(k)!=m.end()) ans += m[k];
            sum+=nums[i];
            k += nums[i];
            m[sum]--;
        }
        return ans;
    }
};