class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.length();
        int l= 0,r=0,cA=0,cB=0,cC=0,ans=0;
        while(r<n)
        {
            if(s[r] == 'a') cA++;
            else if(s[r] == 'b') cB++;
            else if(s[r] == 'c') cC++;
            if(cA > 0 && cB  > 0 && cC > 0)
            {
                while(cA > 0 && cB > 0 && cC > 0 && l<n)
                {
                    ans += n - r;
                    if(s[l] == 'a') cA--;
                    else if(s[l] == 'b') cB--;
                    else if(s[l] == 'c') cC--;
                    l++;
                }
            }
            r++;
        }    

        return ans;
    }
};