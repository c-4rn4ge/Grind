class Solution
{
public:
    int mod = 1e9 + 7;
    int dp[20001][120];
    int solve(int n, char prev)
    {
        if (n == 0)
            return 1;
        if (dp[n][prev] != -1)
            return dp[n][prev];
        int c = 0;
        if (prev == 'b')
        {
            c = (c + solve(n - 1, 'a')) % mod;
            c = (c + solve(n - 1, 'e')) % mod;
            c = (c + solve(n - 1, 'i')) % mod;
            c = (c + solve(n - 1, 'o')) % mod;
            c = (c + solve(n - 1, 'u')) % mod;
        }
        else if (prev == 'a')
            c = (c + solve(n - 1, 'e')) % mod;
        else if (prev == 'e')
        {
            c = (c + solve(n - 1, 'a')) % mod;
            c = (c + solve(n - 1, 'i')) % mod;
        }
        else if (prev == 'i')
        {
            c = (c + solve(n - 1, 'a')) % mod;
            c = (c + solve(n - 1, 'e')) % mod;
            c = (c + solve(n - 1, 'o')) % mod;
            c = (c + solve(n - 1, 'u')) % mod;
        }
        else if (prev == 'o')
        {
            c = (c + solve(n - 1, 'i')) % mod;
            c = (c + solve(n - 1, 'u')) % mod;
        }
        else
            c = (c + solve(n - 1, 'a')) % mod;
        return dp[n][prev] = c;
    }
    int countVowelPermutation(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n, 'b');
    }
};