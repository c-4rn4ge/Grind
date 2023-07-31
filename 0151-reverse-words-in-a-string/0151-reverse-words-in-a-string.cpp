class Solution {
public:
    string reverseWords(string s) 
    {
        string temp = "",str = "";
        vector<string> ans;
        for(int i=0;i<s.length();i++)
        {
            while(s[i] != ' ' && i<s.length())
            {
                temp += s[i];
                i++;
            }

            if(temp.length() != 0)
            {
                ans.push_back(temp);
                temp = "";
            }
        }

        for(int j = ans.size()-1; j >= 0;j--)
        {
            str += ans[j];
            if(j != 0)  str += " ";
        }
        return str;
    }
};