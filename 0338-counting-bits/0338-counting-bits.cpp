class Solution 
{
public:
    int countbits(int num)
    {
        int count = 0;
        while(num>0)
        {
            num = num&(num-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(countbits(i));
        }
        return ans;
    }
};