class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        int n = stones.size();
        if(stones[1]>1)   return false;
        if(n==2)        return (stones[1]-stones[0]==1);
        vector<vector<bool>> dp(n, vector<bool> (n+1, false));
        dp[0][1] = true;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int d = stones[i] - stones[j];
                if(d > n || dp[j][d] == false)    continue;
                if(i == n - 1)                  return true;
                dp[i][d] = true;
                if(d - 1 >= 0) dp[i][d - 1] = true;
                if(d + 1 <= n) dp[i][d + 1] = true;
            }
        }
        return false;    
    }
};