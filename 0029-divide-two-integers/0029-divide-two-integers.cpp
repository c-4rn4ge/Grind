class Solution 
{
public:
    int divide(int divd, int divs) 
    {
        if(divd == INT_MIN && divs == -1)    return INT_MAX;
        return divd/divs;
    }
};