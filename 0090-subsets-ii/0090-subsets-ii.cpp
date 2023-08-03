class Solution {
public:
    void solve(vector<int> &a, vector<int> &t, vector<vector<int>> &ans,int i,int n)
    {
        ans.push_back(t);
        for(int j = i;j<n;j++)
        {
            if(j!=i && a[j] == a[j-1]) continue;
            t.push_back(a[j]);
            solve(a,t,ans,j+1,n);
            t.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) 
    {
        vector<int> t;
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        solve(a,t,ans,0,a.size());
        return ans;
    }
};