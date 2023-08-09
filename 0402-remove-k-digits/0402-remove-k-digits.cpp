class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if(num.length() <= k)   return "0";
        if(k == 0)              return num;
        string res = "";
        stack <char> s; 
        s.push(num[0]); 
        for(int i = 1; i<num.length(); ++i)
        {
            while(k > 0 && !s.empty() && num[i] < s.top())
            {
                k--;
                s.pop();
            }
            if((!s.size() && num[i] != '0') || s.size() > 0)  s.push(num[i]);
        }
        
        while(k && !s.empty())
        {
            --k;
            s.pop();
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        if(!res.length())   return "0";
        return res;
    }
};