class Solution 
{
public:
    int cA=0,cB=0,cC=0;
    void doit(char a, char op)
    {
        if(a == 'a' && op == '+') cA++;
        else if(a == 'a' && op == '-') cA--;
        else if(a == 'b' && op == '+') cB++;
        else if(a == 'b' && op == '-') cB--;
        else if(a == 'c' && op == '+') cC++;
        else if(a == 'c' && op == '-') cC--;
    }
    int numberOfSubstrings(string s) 
    {
        int l= 0,r=0,ans=0;
        int n = s.length();
        while(r<n)
        {
            doit(s[r] , '+');
            if(cA > 0 && cB  > 0 && cC > 0)
            {
                while(cA > 0 && cB > 0 && cC > 0 && l<n)
                {
                    ans += n - r;
                    doit(s[l++] , '-' );
                }
            }
            r++;
        }    

        return ans;
    }
};