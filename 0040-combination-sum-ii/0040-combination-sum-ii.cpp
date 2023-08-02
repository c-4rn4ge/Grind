class Solution {
public:
    void solve(vector<int> &a,vector<int> &t,vector<vector<int>> &ans,int i,int k ,int n)
    {
        if(k<0) return;
        if(k==0) {ans.push_back(t);return;}
        for(int j = i;j<n;j++)
        {
            if(j > i && a[j]==a[j-1]) continue;
            t.push_back(a[j]);
            solve(a,t,ans,j+1,k-a[j],n);
            t.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int k) 
    {
        sort(a.begin(),a.end());
        vector<int> t;vector<vector<int>> ans;
        solve(a,t,ans,0,k,a.size());
        return ans;
    }
};