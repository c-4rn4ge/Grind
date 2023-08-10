class Solution {
public:
    int totalFruit(vector<int>& a) 
    {
        int n = a.size(),ans=0,i,j=0;
        unordered_map<int,int> mp;
        for(i=0;i<n;i++)
        {
            mp[a[i]]++;
            if(mp.size() > 2)
            {
                mp[a[j]]--;
                if(mp[a[j]]==0) mp.erase(a[j]);
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};