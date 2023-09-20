class Solution 
{
public:
    int solve(long n, int ans)
    {
        if (n <= 1) return ans;
        if (!(n%2))     return solve(n/2, ans+1); 
        else            return min(solve(n+1, ans+1), solve(n-1, ans+1));
    }

    int integerReplacement(int n) 
    {
        return solve(n, 0);
    }
};