class Solution {
public:
    bool isP(string s ,int st,int en)
    {
        while(st<=en)
        {
            if(s[st++]!=s[en--]) return false;  
        }
        return true;
    }
    void solve(string s,vector<vector<string>> &ans,vector<string> &str,int i,int n)
    {
        if(i==n) ans.push_back(str);
        else
        {
            for(int j = i;j<n;j++)
            {
                if(isP(s,i,j))
                {
                    str.push_back(s.substr(i,j-i+1));
                    solve(s,ans,str,j+1,n);
                    str.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s,ans,path,0,s.length());
        return ans;    
    }
};