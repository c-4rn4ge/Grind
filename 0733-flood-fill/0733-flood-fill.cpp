class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m ,int i,int j,int r,int color)
    {
        if(i< 0 || i >= n || j< 0 || j>= m || vis[i][j] || grid[i][j] != r) return;
        grid[i][j] = color;
        vis[i][j] = 1;
        dfs(grid,vis,n,m,i,j+1,r,color);
        dfs(grid,vis,n,m,i+1,j,r,color);
        dfs(grid,vis,n,m,i-1,j,r,color);
        dfs(grid,vis,n,m,i,j-1,r,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),0));
        dfs(image,vis,image.size(),image[0].size(),sr,sc,image[sr][sc],color);
        return image;    
    }
};