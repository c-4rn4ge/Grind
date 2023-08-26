bool cmp(string &s1,string &s2)
{
    return s1.size()<s2.size();
}
class Solution 
{
private:
    bool check(string &s1,string &s2)
    {
        int l1 = s1.size(),l2 = s2.size();
        if(l1 != l2 + 1) return 0;
        int i=0,j=0;
        while(i < l1)
        {
            if(j<l2 && s1[i]==s2[j])
            {
                i++,j++;
            }
            else
            {
                i++;
            }
        }
        return i==l1 && j==l2;
    }
public:
    int longestStrChain(vector<string>& arr) 
    {
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);
        int maxi = 1;
        vector<int> dp(n+1,1);
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < i; j++)
            {
                if(check(arr[i],arr[j]) && 1 + dp[j] > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(dp[i],maxi);
        }
        return maxi;    
    }
};