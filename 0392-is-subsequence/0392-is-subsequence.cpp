class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);cout.tie(nullptr);
        int k =0;
        for(int i=0;i<t.length();i++)if(s[k]==t[i])k++;
        if(k != s.length()) return false;
        return true;
    }
};