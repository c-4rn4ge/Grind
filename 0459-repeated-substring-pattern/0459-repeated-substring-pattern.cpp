class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        int l = s.length() ;
        for(int i=l/2; i>=1; i--) 
        {
            if(l%i == 0) 
            {
                if(s.substr(0,l-i) == s.substr(i)) return true ;
            }
        }
        return false ;
    }
};