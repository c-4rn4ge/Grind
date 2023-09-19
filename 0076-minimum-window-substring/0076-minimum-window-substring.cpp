class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        vector<int> h(128,0);
        for(auto &i: t) h[i]++;
        int c = t.size(), j = 0, i = 0, end = INT_MAX, start = 0,n = s.length();
        while(i < n)
        {
            if(h[s[i++]]-- > 0) c--; 
            while(c==0)
            { 
                if(i-j<end)  end = i - (start = j);
                if(h[s[j++]]++ == 0) c++;  
            }  
        }
        return (end == INT_MAX) ?  "" : s.substr(start, end);
    }
};