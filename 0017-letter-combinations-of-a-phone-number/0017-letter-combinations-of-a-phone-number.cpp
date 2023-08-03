class Solution 
{
private:
    unordered_map<char,string> m{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    void solve(string &d,string c,vector<string> &ans,int i)
    {
        if(c.length()==d.length()) ans.push_back(c);
        else    {string temp = m[d[i]];for(auto j : temp)   solve(d,c+j,ans,i+1);}
    }
public:
    vector<string> letterCombinations(string d) 
    {
        if(d.length()==0) return {};
        vector<string> ans;
        solve(d,"",ans,0);
        return ans;
    }
};