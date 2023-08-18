class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> que;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow[] = {-1, 0, +1, 0}; 
	    int delCol[] = {0, +1, 0, -1}; 

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                if((i == 0 || j == 0 || i == n-1 
                || j == m-1) && board[i][j] == 'O')
                {
                    que.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }    
        
        while(!que.empty())
        {
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            for(int i = 0 ; i < 4 ; i++ )
            {
                int nr = row + delRow[i];
                int nc = col + delCol[i];
                if(nr < n && nr >= 0 && nc >= 0 && nc < m 
                && !vis[nr][nc] && board[nr][nc] == 'O')
                {
                    que.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(vis[i][j]==0 && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};