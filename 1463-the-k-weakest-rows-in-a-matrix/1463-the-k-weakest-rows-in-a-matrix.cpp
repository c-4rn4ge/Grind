class Solution {
public:
    int bs(vector<int> &a)
    {
        int l = 0,h = a.size()-1,m;
        while(l<=h)
        {
            m = l + (h-l)/2;
            if(a[m]==1) l = m+1;
            else
            {
                if(a[l]==0) return l;
                l++;
                h = m;
            }
        }
        return a.size();
    }   
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<pair<int,int>> m;
        vector<int> ans;
        for(int i=0;i<mat.size();i++)  
            m.push_back({bs(mat[i]),i});
        sort(m.begin(),m.end());
        for(int i = 0; i<k ;i++)       
            ans.push_back(m[i].second);
        return ans;
    }
};