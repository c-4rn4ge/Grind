class Solution
{
private:
public:
    int minFallingPathSum(vector<vector<int>> &gr)
    {
        int r = gr.size();
        int c = gr[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        for (int i = 0; i < c; i++)
        {
            dp[0][i] = gr[0][i];
        }

        for (int i = 1; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                int u = gr[i][j] + dp[i - 1][j];
                
                int ld = gr[i][j];
                if (j - 1 >= 0) ld += dp[i - 1][j - 1];
                else            ld += 1e8;

                int rd = gr[i][j];
                if (j + 1 < c)  rd += dp[i - 1][j + 1];
                else            rd += 1e8;

                dp[i][j] = min(u, min(ld, rd));
            }
        }

        for (int i = 0; i < c; i++)
        {
            ans = min(ans, dp[r - 1][i]);
        }
        return ans;
    }
};