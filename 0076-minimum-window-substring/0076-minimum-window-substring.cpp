class Solution 
{
private:
    vector<int> ht;
    vector<int> st;
public:
    Solution()
    {
       ht.resize(123);
       st.resize(123);
    }
    bool check()
    {
        for(int i=65;i<123;i++)
        {
            if(ht[i] != 0 && ht[i] > st[i]) return false;
        }   
        return true;
    }
    string minWindow(string s, string t) 
    {
        int l = 0,r=0,sl=s.size(),tl = t.length();
        string ans = "";
        int c = INT_MAX;
        if(s.size() < t.size()) return "";
        for(int i=0;i<tl;i++)   ht[t[i]]++;
        while(r < sl)
        {
            st[s[r]]++;
            while(l <= r && (ht[s[l]] == 0 || st[s[l]] > ht[s[l]])) st[s[l++]]--;
            if(check())
            {
                if(c > r - l + 1)   ans = s.substr(l,c = r - l + 1);
                st[s[l++]]--;
            }
            r++;
        }
        return ans;
    }
};