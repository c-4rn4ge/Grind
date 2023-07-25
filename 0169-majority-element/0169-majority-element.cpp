class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        int max =INT_MIN,ans=INT_MIN;
        for(int i = 0;i< nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto it= m.begin(); it != m.end() ;it++)
        {
            if (it->second > max ) {max = it->second ; ans = it->first;}
        }
        return ans;
    }
};