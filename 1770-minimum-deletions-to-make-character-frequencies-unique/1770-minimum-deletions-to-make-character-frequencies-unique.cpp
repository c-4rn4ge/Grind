class Solution 
{
public:
    int minDeletions(string s) 
    {
        vector<int> h(26, 0);
        for (int i = 0; i < s.length(); i++)    h[s[i]-97]++; 
        sort(h.begin(), h.end());
        int ans = 0;
        for (int i = 24; i >= 0; i--) 
        {
            if (h[i] == 0) break;
            if (h[i] >= h[i + 1]) 
            {
                int p = h[i];
                h[i] = max(0, h[i + 1] - 1);
                ans += p - h[i];
            }
        }
        return ans;
    }
};