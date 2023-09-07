class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.length(),maxLen = 0,l=0,r=0;
        unordered_map<char,int> mp;
        while(r < n)
        {
            mp[s[r]]++;
            while(mp[s[r]] > 1) mp[s[l++]]--;
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;        
    }
};