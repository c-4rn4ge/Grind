class Solution 
{
    static bool cmp(vector<int>& a, vector<int>& b) 
    {
        return a[1] < b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),pairs.end(),cmp);
        int ans = 1;
        int j = 0;
        for(int i = 1 ; i < pairs.size() ;i++)
        {
            if(pairs[j][1] < pairs[i][0]) ans ++,j=i;
        }
        return ans;
    }
};