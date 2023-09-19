class Solution 
{
public:
    long long mod = 1000000007;
    long long solve(string &s , long long k ,long long i, vector<long long> &dp)
    {
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        long long sum = 0,curr = 0;
        for(long long j = i; j < s.length(); j++)
        {
            sum = (sum * 10 + (s[j] - '0'));
            if(sum >=1 && sum <= k) curr = (curr + solve(s,k,j+1,dp)) % mod;
            else break;
        }
        return dp[i] = curr;
    }
    int numberOfArrays(string s, int k) 
    {
        vector<long long> dp(100001,-1);
        return (int)solve(s,k,0,dp); 
    }
};
