class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<char> st;
        if(k == num.size()) return "0";
        for(int i = 0; i < num.size(); i++) 
        {
            while(!st.empty() && num[i] < st.top() && k ) 
            {
                st.pop();
                k--;
            }
            if(st.size() || num[i] != '0')st.push(num[i]);
        }
        while(st.size() && k--) 
        {
            st.pop();
        }
        string ans;
        while(!st.empty()) 
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return (ans.size()) ? ans : "0";
    }
};