#define ll long long
#define fastasfuckboi ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define For(i,n) 	for(int i = 0; i < n; i++)
#define nl cout<<"\n";
class Solution
{
public:
    int solve(vector<bool> &col, vector<bool> &ld, vector<bool> &rd, int i)
    {
        fastasfuckboi
        int n = col.size(), ans = 0;
        if (i == n)   return 1;
        for (int j = 0; j < n; j++)
        {
            if (!col[j] && !ld[i + j] && !rd[i - j + n - 1])
            {
                col[j] = ld[i + j] = rd[i - j + n - 1] = true;
                ans += solve(col, ld, rd, i + 1);
                col[j] = ld[i + j] = rd[i - j + n - 1] = false;
            }
        }
        return ans;
    }
    int totalNQueens(int n)
    {
        fastasfuckboi
        vector<bool> col(n), ld(2 * n - 1), rd(2 * n - 1);
        return solve(col, ld, rd, 0);
    }
};