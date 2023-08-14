class Solution 
{
public:
    void f(int i, int j, int m, int n, vector<vector<char>>& grid) 
    {

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;    
        grid[i][j] = '2';
        f(i, j+1, m, n, grid);
        f(i+1, j, m, n, grid);
        f(i, j-1, m, n, grid);
        f(i-1, j, m, n, grid);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int cnt = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++) 
            {
                if(grid[i][j] == '1') 
                {
                    cnt++;
                    f(i, j, grid.size(), grid[0].size(), grid);
                }
            }
        }
        
        return cnt;
    }
};