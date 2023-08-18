class Solution 
{
private: 
    void dfs(vector<vector<int>>& grid , vector<vector<int>>& vis,
    int n ,int m , int i , int j,int delrow[],int delcol[])
    {
        vis[i][j] = 1;
        for(int a = 0 ; a < 4 ; a++)
        {
            int nr = i + delrow[a];
            int nc = j + delcol[a];

            if(nr<n && nc < m && nr >= 0 && nc >= 0 
            && !vis[nr][nc] && grid[nr][nc])
            {
                dfs(grid,vis,n ,m,nr,nc,delrow,delcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) 
                && grid[i][j] && !vis[i][j])
                {
                    dfs(grid,vis,n,m,i,j,delrow,delcol);
                }
            }
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(!vis[i][j] && grid[i][j]) ans++;
            }
        }    
        return ans;
    }
};