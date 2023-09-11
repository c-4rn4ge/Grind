class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0,j=0,i=0,n = g.size(),m = s.size();
        while(i <  n && j < m)
        {
            if(s[j]>=g[i])  i++,ans++;
            j++;
        } 
        return ans;       
    }
};