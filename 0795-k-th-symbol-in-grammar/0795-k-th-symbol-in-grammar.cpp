class Solution 
{
public:
    int kthGrammar(int n, int k) 
    {
        if (n == 1)     return 0;
        int a = kthGrammar(n - 1, (k + 1) / 2);
        if (k % 2 == 0) return (a == 1) ? 0 : 1;
        else    return a;
    }
};