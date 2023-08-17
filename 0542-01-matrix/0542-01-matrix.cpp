class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,0));
        vector<vector<int>>  vis(n,vector<int>(m,0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m ;j++)
            {
                if(!mat[i][j])
                {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[r][c] = steps;
            for(int i = 0;i<4;i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow>=0 && nrow < n && ncol>=0 && ncol < m 
                && mat[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dist;
    }
};