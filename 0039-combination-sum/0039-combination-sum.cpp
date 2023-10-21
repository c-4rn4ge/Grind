#define fastasfuckboi                 \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr);                 \
	cout.tie(nullptr);
class Solution 
{
public:
    void solve(vector<int> &a,vector<int> &t,vector<vector<int>> &ans,int i,int key,int n)
    {
        fastasfuckboi
        if(i==n)    {if(key==0)  ans.push_back(t);return;} 
        if(a[i]<=key)
        {
            t.push_back(a[i]);
            solve(a,t,ans,i,key-a[i],n);
            t.pop_back();
        }
        solve(a,t,ans,i+1,key,n);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int k) 
    {
        fastasfuckboi
        vector<vector<int>> ans;
        vector<int> t;
        solve(a,t,ans,0,k,a.size());
        return ans;
    }
};