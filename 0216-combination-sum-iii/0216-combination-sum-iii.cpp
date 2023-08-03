class Solution {
public:
    void solve(vector<int> &num,vector<int> &a,vector<vector<int>> &ans,int i,int k,int n)
    {
        if(n<0) return;
        if(i==9) {if(n==0 && a.size()==k) ans.push_back(a);return;}
        a.push_back(num[i]);
        solve(num,a,ans,i+1,k,n-num[i]);
        a.pop_back();
        solve(num,a,ans,i+1,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> a,num;
        for(int i = 1;i<=9;i++) num.push_back(i);
        solve(num,a,ans,0,k,n);
        return ans;
    }
};