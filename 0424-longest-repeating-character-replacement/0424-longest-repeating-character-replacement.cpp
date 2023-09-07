class Solution 
{
public:
    int characterReplacement(string s, int k) 
    {
        int map[26] = {0};    
        int maxf=0,ans=0,l=0;
        for(int i=0;i<s.length();i++)
        {
            maxf = max(maxf,++map[s[i]-'A']);
            if((i - l + 1) - maxf >  k)    map[s[l++]-'A']--;
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};