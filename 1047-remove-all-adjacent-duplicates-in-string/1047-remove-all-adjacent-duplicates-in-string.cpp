class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> stk;
        for(int i = 0;i<s.length();i++)
        {
            if(!stk.size()) stk.push(s[i]);
            else
            {
                if(stk.top() == s[i]) stk.pop();
                else stk.push(s[i]);
            }
        }
        if(!stk.size()) return "";
        string ans = "";
        while(stk.size())
        {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};