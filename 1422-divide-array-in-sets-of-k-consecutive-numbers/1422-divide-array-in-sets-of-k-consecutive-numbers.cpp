class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n % k != 0)    return false;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]]++;
        sort(nums.begin(),nums.end());
        int i = 0,c = 0;
        while(i < n) 
        {
            int c1 = 0, t = nums[i];
            while(c1 < k && mp.find(t)!=mp.end()) 
            {
                if(mp[t]==1) mp.erase(t);
                else mp[t]--;
                c1 ++;
                t++;
            }
            if(c1 == k) c++;
            i++;
        }
        return (c == n / k);    
    }
};