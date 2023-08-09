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
            st.push(num[i]);
        }
        while(k--) 
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
        int ind;
        for(int i = 0; i < ans.size(); i++) 
        {
            if(ans[i] != '0') 
            {
                ind = i;
                break;
            }
        }
        if(ans.substr(ind).size() == 0) return "0";
        return ans.substr(ind);
    }
};