class Solution {
public:
    void solve(vector<int> a, vector<int> &t, vector<vector<int>> &ans, int i, int n , int key)
    {
        if(i==n)    {if(key==0)  ans.push_back(t);return;} 
        if(a[i]<=key)
        {
            t.push_back(a[i]);
            solve(a,t,ans,i,n,key-a[i]);
            t.pop_back();
        }
        solve(a,t,ans,i+1,n,key);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int key) 
    {
       vector<vector<int>> ans;vector<int> temp;
       solve(a,temp,ans,0,a.size(),key);
       return ans; 
    }
};