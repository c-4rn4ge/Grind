class Solution {
public:
    void solve(string & s, vector<string> &ans,int n,int c,int o)
    {
        if(c==n && o==n) ans.push_back(s);
        else
        {
            if(o<=n)
            {
                s.push_back('(');
                solve(s,ans,n,c,o+1);
                s.pop_back();
            }
            if(c<o) 
            {
                s.push_back(')');
                solve(s,ans,n,c+1,o);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string s;
        solve(s,ans,n,0,0);
        return ans;
    }
};