class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        int count = 0,sum=0;
        unordered_map <int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum == k)    count++;
            if(m.find(sum-k)!=m.end())  count += m[sum-k];
            m[sum]++;
        }
        return count;
    }
};