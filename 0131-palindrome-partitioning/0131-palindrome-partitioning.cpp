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
    void solve(string s,vector<vector<string>> &ans,vector<string> &path,int ind,int n)
    {
        if(ind == n) ans.push_back(path);
        else
        {
            for(int i = ind ;i <n;i++)
            {
                if(isP(s,ind, i))
                {
                    path.push_back(s.substr(ind,i-ind+1));
                    solve(s,ans,path,i+1,s.length());    
                    path.pop_back();
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