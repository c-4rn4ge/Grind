class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size(),ans=0;
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> que;
        vis[0][0] = 1;
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};
        que.push({{0,0},1});
        while(!que.empty())
        {
            int row = que.front().first.first;
            int col = que.front().first.second;
            int curLen = que.front().second;
            if(row == n-1 && col == n-1) return curLen;
            que.pop();
            for(int i = 0; i < 8; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr < n && nc < n && nr >= 0 && nc >= 0 && !vis[nr][nc] && !grid[nr][nc])
                {
                    vis[nr][nc] = 1;
                    que.push({{nr,nc},curLen+1});
                } 
            }
        }
        return -1;
    }
};