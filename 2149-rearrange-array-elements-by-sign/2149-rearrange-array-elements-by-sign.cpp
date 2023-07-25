class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        queue<int> q1,q2;int i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]>0) q1.push(nums[i]);
            else q2.push(nums[i]);
        }
        i=0;
        while(!q1.empty() || !q2.empty())
        {
            if(!q1.empty()) {nums[i++]=q1.front();q1.pop();}
            if(!q2.empty()){nums[i++]=q2.front();q2.pop();}
        }
        return nums;
    }
};