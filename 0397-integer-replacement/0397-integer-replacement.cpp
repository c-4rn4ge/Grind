class Solution 
{
private:
    long long solve(long long n)
    {
        if(n <= 1) return 0;
        long long left = INT_MAX,ch1 = INT_MAX,ch2 = INT_MAX;
        if(!(n % 2)) left = 1 + solve(n/2);
        else
        {
            ch1 = 1 + solve(n-1);
            ch2 = 1 + solve(n+1);
        }
        return min(left,min(ch1,ch2));
    }
public:
    int integerReplacement(int n) 
    {
        return (int)solve((long long)n);
    }
};