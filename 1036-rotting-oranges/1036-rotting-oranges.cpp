class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<pair<int,int>,int>> que;
        int n = grid.size(),m = grid[0].size();
        int vis[n][m];
        int ans = 0,t_max = 0 ;
        int dir_1[] = {-1, 0, +1, 0};
        int dir_2[] = {0, -1, 0, +1};
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(grid[i][j] == 2 )
                {
                    que.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        while(!que.empty())
        {
            int r = que.front().first.first;
            int c = que.front().first.second;
            int t = que.front().second;
            t_max = max(t_max , t);
            que.pop();
            for(int i = 0; i < 4;i++)
            {
                int  new_r = r + dir_1[i];
                int  new_c = c + dir_2[i];
                if(new_r >= 0 && new_r < n && new_c >=0 && new_c < m && vis[new_r][new_c] != 2 && grid[new_r][new_c] == 1)
                {
                    que.push({{new_r,new_c},t+1});
                    vis[new_r][new_c] = 2;
                }
            }
        }
        for(int i = 0;i< n;i++)
        {
            for(int j = 0; j< m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] != 2)
                {
                    return -1;
                }
            }
        }
        return t_max;
    }
};