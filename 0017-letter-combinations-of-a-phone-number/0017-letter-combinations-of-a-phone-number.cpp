class Solution {
public:
    vector<string> dict = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string &s,string str,vector<string> &ans,int i)
    {
        if(i==s.length()) 
        {
            ans.push_back(str);
            return;
        }
        string temp = dict[s[i]-48];
        for(int j= 0;j<temp.length();j++)
        {
            solve(s,str+temp[j],ans,i+1);
        }
    }
    vector<string> letterCombinations(string s) 
    {
        if(s.length()==0) return{};
        vector<string> ans;
        solve(s,"",ans,0);
        return ans;
    }
};