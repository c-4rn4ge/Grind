class Solution
{
public:
    int minDistance(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<int> p(n + 1, 0), c(n + 1, 0);
        for (int i = 1; i <= n; i++)
            p[i] = i;
        for (int i = 1; i <= m; i++)
        {
            c[0] = i;
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    c[j] = p[j - 1];
                else
                    c[j] = min(p[j - 1], min(c[j - 1], p[j])) + 1;
            }
            p = c;
        }
        return p[n];
    }
};