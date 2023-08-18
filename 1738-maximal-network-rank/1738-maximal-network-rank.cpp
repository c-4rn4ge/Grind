class Solution 
{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<int> count(n,0);
        vector<vector<int>> direct(n,vector<int>(n,0));

        for (auto &i : roads) 
        {
            count[i[0]]++;
            count[i[1]]++;
            direct[i[0]][i[1]] = 1;
            direct[i[1]][i[0]] = 1;
        }

        int rank = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                rank = max(rank, count[i] + count[j] - direct[i][j]);
            }
        }
        return rank;
    }
};