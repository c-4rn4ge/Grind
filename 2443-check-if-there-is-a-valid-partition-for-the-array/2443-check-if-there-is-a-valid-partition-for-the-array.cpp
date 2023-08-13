class Solution 
{
public:
    bool validPartition(std::vector<int>& a) 
    {
        int n = a.size();
        bool dp[3] = {true, false, (a[0] == a[1])};
        for (int i = 2; i < n; i++) 
        {
            bool t = false;
            if (a[i] == a[i-1] && dp[1]) t = true;
            else if (i-2 >= 0 && a[i] == a[i-1] && a[i] == a[i-2] && dp[0]) t = true;
            else if (i-2 >= 0 && a[i] - a[i-1] == 1 && a[i-1] - a[i-2] == 1 && dp[0])   t = true;
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = t;
        }
        return dp[2];
    }
};