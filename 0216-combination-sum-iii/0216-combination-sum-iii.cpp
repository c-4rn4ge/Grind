class Solution {
public:
    void solve(vector<int> &a,vector<vector<int>> &ans,int i,int k,int n)
    {
        if(n<0) return;
        if(i==9) {if(n==0 && a.size()==k) ans.push_back(a);return;}
        a.push_back(i+1);
        solve(a,ans,i+1,k,n-(i+1));
        a.pop_back();
        solve(a,ans,i+1,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> a,num;
        solve(a,ans,0,k,n);
        return ans;
    }
};