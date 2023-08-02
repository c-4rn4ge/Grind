class Solution {
public:
    void solve(vector<int> &a, vector<int> &t, vector<vector<int>> &ans,int i,int n)
    {
        if(i>=n) ans.push_back(t);
        else
        {
            t.push_back(a[i]);
            solve(a,t,ans,i+1,n);
            t.pop_back();
            solve(a,t,ans,i+1,n);
        }
    }
    vector<vector<int>> subsets(vector<int>& a) 
    {
        vector<int> t;
        vector<vector<int>> ans;
        solve(a,t,ans,0,a.size());
        return ans;
    }
};