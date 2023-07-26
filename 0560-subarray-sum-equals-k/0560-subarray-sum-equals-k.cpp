class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count=0,i,n=nums.size(),sum=0;
        unordered_map<int,int> m;
        for(i=0;i<n;i++)
        {
            sum += nums[i];
            m[sum]++;
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(m.find(k)!=m.end()) count+=m[k];
            m[sum]--;
            k+=nums[i];
        }
        return count;   
    }
};