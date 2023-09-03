class Solution 
{
    int solve(string &num,int d1,int d2,int n)
    {
        int c1=0,c2=0;
        for(int i = n-1 ; i>= 0; i--)
        {
            if(num[i]-48 == d2 && c2==0)
            {
                c2=1;
            }
            else if(num[i]-48 == d1 && c2==1)
            {
                return n-i-2;
            }
        }
        return 1e9;
    }
public:
    int minimumOperations(string num) 
    {
        int c = 0,ans=1e9,n=num.length();
        ans = min(ans,solve(num,0,0,n));
        ans = min(ans,solve(num,2,5,n));
        ans = min(ans,solve(num,5,0,n));
        ans = min(ans,solve(num,7,5,n));
        for(auto &i : num) if(i=='0') c++;
        ans = min(ans,n-c);
        return ans;
    }
};