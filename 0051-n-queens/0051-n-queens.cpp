class Solution {
public:
    void solve(vector<string> &board,vector<vector<string>> &ans,vector<int> &left,vector<int>&ud,vector<int>&ld,int n,int c)
    {
        if(c==n) ans.push_back(board); 
        else
        {
            for(int i = 0;i<n;i++)
            {
                if( !left[i] && !ld[i+c] && !ud[n-1+i-c])
                {
                    board[i][c] = 'Q';
                    left[i] = ld[i+c] = ud[n-1+i-c]= 1;
                    solve(board,ans,left,ud,ld,n,c+1);
                    board[i][c] = '.';
                    left[i] = ld[i+c] = ud[n-1+i-c]= 0;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n,'.');
        for(int i =0;i<n;i++) board[i] = s;
        vector<int> left(n,0),ud(2*n-1,0),ld(2*n-1,0);
        solve(board,ans,left,ud,ld,n,0);
        return ans;   
    }
};