class Solution 
{
public:
    bool solve(vector<vector<char>>& board,string word,int row,int col)
    {
        if( !word.length() ) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[0] ) return false;
        string s = word.substr(1);
        char c = board[row][col];
        board[row][col]='*';
        bool var = solve(board,s,row,col+1) || solve(board,s,row+1,col) || solve(board,s,row-1,col) || solve(board,s,row,col-1) ;
        board[row][col]=c;
        return var;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {    
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j]==word[0])    if(solve(board, word, i, j))    return true;
            }
        }
        return false;
    }
};