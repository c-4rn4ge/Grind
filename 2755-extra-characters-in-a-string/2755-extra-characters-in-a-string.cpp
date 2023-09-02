class Solution
{
public:
    int minExtraChar(string s, vector<string> &dict)
    {
        int n = s.length() + 1;
        vector<int> dp(n, n);
        dp[0] = 0;
        unordered_set<string> st(dict.begin(), dict.end());
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + 1;
            for (int l = 1; l <= i; l++)
            {
                if (st.find(s.substr(i - l, l)) != st.end())
                {
                    dp[i] = min(dp[i], dp[i - l]);
                }
            }
        }
        return dp.back();
    }
};