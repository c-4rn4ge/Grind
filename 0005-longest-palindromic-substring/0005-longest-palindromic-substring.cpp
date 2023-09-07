class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        if(n==0) return "";
        if(n==1) return s;
        int start = 0, end = 0,i=0;
        while(i<n)
        {
            if(n-i < end/2) break;
            int l = i, r = i;
            while(r < n && s[r] == s[r + 1])    r++;
            i = r + 1;
            while(l > 0 && r < n && s[l-1] == s[r+1])   l--,r++;
            int newlen = r - l + 1;
            if(newlen > end)
            {
                end = newlen;
                start = l;
            }
        }
        return s.substr(start,end);   
    }
};