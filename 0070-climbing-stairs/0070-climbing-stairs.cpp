class Solution 
{
public:
    int climbStairs(int n) 
    {
        int a ,b;
        a = 0; b = 1;
        for(int i = 1; i <= n; i++)   
        {
            int c = a + b;      
            a = b;
            b = c;
        }
        return b;
    }
};