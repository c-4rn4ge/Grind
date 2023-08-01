#define m 1000000007
class Solution {
public:
    long long calc(int x, long long n)
    {
        if(n==0)    return 1;
        x = x % m;
        long long val = calc(x,n/2) ;
        long long ans = (val*val) % m;
        if(n%2==0)  return ans;
        else        return (ans*x) % m;
    }

    int countGoodNumbers(long long n) 
    {
        long long odd_places = n/2;
        long long even_places = n/2 + n % 2;
        long long four_pow = calc(4,odd_places) % m;
        long long five_pow = calc(5,even_places) % m;
        return int((four_pow*five_pow) % m);
    }
};