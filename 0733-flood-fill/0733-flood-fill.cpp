class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        int r = ans[sr][sc];
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, -1, 0, +1};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ans[row][col] = color;
            for (int i = 0; i < 4; i++)
            {
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if ((nr >= 0 && nr < n) && (nc >= 0 && nc < m) && ans[nr][nc] == r && ans[nr][nc] != color)
                {
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};