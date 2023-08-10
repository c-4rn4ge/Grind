class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char,int> map;    
        int maxf=0,ans=0,l=0;
        for(int i=0;i<s.length();i++)
        {
            map[s[i]]++;
            maxf = max(maxf,map[s[i]]);
            while( (i - l + 1) - maxf >  k)    map[s[l++]]--;
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};