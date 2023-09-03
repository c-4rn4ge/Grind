class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        pq.push({0, {0, 0}});
        dis[0][0] = 0;
        while (!pq.empty())
        {
            auto curNode = pq.top();
            pq.pop();
            int diff = curNode.first;
            int r = curNode.second.first;
            int c = curNode.second.second;
            if (r == n - 1 && c == m - 1)    return dis[r][c];
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m)
                {
                    int currDiff = abs(grid[r][c] - grid[nr][nc]);
                    int newMax = max(currDiff, diff);
                    if (newMax < dis[nr][nc])
                    {
                        dis[nr][nc] = newMax;
                        pq.push({newMax, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};