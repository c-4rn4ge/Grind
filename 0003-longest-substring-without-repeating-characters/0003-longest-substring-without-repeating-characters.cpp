class Solution 
{
    public:
    int lengthOfLongestSubstring(string str) 
    {
        vector<int> h(256, -1);
        int ans = 0, s = -1;
        for (int i = 0; i != str.length(); i++) 
        {
            if (h[str[i]] > s)
                s = h[str[i]];
            h[str[i]] = i;
            ans = max(ans, i - s);
        }
        return ans;
    }
};