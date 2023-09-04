class Solution 
{
public:
    bool rotateString(string s, string g) 
    {
        if(s.length() != g.length()) return false;
        if(s==g) return true;
        int l = s.length();
        queue<char> q1,q2;
        for(auto i:s) q1.push(i);
        for(auto i:g) q2.push(i);
        while(l--)
        {
            char c = q2.front();
            q2.pop();
            q2.push(c);
            if(q1==q2) return true;
        }
        return false;
    }
};