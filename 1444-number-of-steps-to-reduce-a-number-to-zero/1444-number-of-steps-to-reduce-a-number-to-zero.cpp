class Solution 
{
public:
    int numways(int n,int *count)
    {
        if(n==0) return *(count);
        (*count)++;
        if(n%2==0)  return numways(n/2,count);
        else        return numways(n-1,count);
    }
    int numberOfSteps(int num) 
    {
        int count = 0;
        return numways(num,&count);
    }
};