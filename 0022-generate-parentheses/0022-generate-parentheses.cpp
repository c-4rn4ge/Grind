class Solution {
public:
    void solve(string & s, vector<string> &ans,int n,int c,int o)
    {
        if(c==0 && o==0) ans.push_back(s);
        else
        {
            if(o>0)
            {
                s.push_back('(');
                solve(s,ans,n,c,o-1);
                s.pop_back();
            }
            if(c>o) 
            {
                s.push_back(')');
                solve(s,ans,n,c-1,o);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string s;
        solve(s,ans,n,n,n);
        return ans;
    }
};