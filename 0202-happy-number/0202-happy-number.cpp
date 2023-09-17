class Solution 
{
private:
    int sum(int n)
    {
        int s = 0;
        while(n!=0)
        {
            int r = n%10;
            s += r*r;
            n /= 10;
        }
        return s;
    }
public:
    bool isHappy(int n) 
    {
        int s = n;
        int f = sum(n);
        while(f != 1 && f != s)
        {
            s = sum(s);
            f = sum(sum(f));
        }
        return f==1;
    }
};