class Solution 
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        int n= mat.size();
        int m = mat[0].size();
        vector<int> ans;
        vector<pair<int,int>> v;
        for(int i = 0;i<n;i++)
        {
            int val = lower_bound(mat[i].begin(),
            mat[i].end(),0,greater<int>())-mat[i].begin();
            v.push_back({val,i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;

    }
};