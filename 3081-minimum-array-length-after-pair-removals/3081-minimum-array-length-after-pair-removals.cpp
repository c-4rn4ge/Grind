class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int>mp;
        priority_queue<int>pq;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto &it : mp)
        {
            pq.push(it.second);
        }
        while(pq.size() != 1 && pq.size() != 0)
        {
            int a=pq.top()-1;pq.pop();
            int b=pq.top()-1;pq.pop();
            if(a)pq.push(a);
            if(b)pq.push(b);
        }
       return pq.size() ? pq.top() : 0;   
    }
};