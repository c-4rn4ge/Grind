class Solution {
public:
    void dfs(vector<vector<char>>& grid ,vector<vector<int>>& vis,int n,int m ,int i,int j)
    {
        if(i< 0 || i >= n || j< 0 || j>= m || vis[i][j] || grid[i][j] == '0') return;
        vis[i][j] = 1;
        dfs(grid,vis,n,m,i,j+1);
        dfs(grid,vis,n,m,i+1,j);
        dfs(grid,vis,n,m,i-1,j);
        dfs(grid,vis,n,m,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int rowSize = grid.size(),colSize = grid[0].size(),ans=0;
        vector<int> a(colSize,0);
        vector<vector<int>> vis(rowSize,a);
        for(int row = 0 ; row < rowSize ; row++)
        {
            for(int col = 0 ; col < colSize ; col++)
            {
                if(grid[row][col] == '1' && !vis[row][col])
                {
                    dfs(grid,vis,rowSize,colSize,row,col);
                    ans += 1;
                }
            }
        }
        return ans;    
    }
};