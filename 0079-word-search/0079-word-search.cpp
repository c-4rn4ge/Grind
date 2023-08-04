class Solution {

public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size(), n = board[0].size(), k=0;
        for(int i=0; i<m; i++)  for(int j=0; j<n; j++)  if(board[i][j] == word[k])  if(recurse(board,word,i,j,k))   return true;
        return false;
    }
    bool recurse(vector<vector<char>>&v, string s, int i, int j, int k)
    {
        if(i<0||i>=v.size()||j<0||j>=v[0].size()||v[i][j]=='*'||v[i][j]!=s[k])  return false;
        if(k==s.length()-1) return true;
        char ch = v[i][j];
        v[i][j] = '*';
        bool ans = recurse(v,s,i+1,j,k+1) || recurse(v,s,i,j+1,k+1) || recurse(v,s,i-1,j,k+1) || recurse(v,s,i,j-1,k+1);
        v[i][j] = ch;
        return ans;
    }
};