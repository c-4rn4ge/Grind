class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int i = 0,j = 0,x = 0,y = 0;
        int m = size(mat), n = size(mat[0]);
        if(r * c != m * n) return mat;
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++)
        {
            vector<int> v1;
            for (int j = 0; j < c; j++)
            {
                v1.push_back(mat[x][y]);
                if(y==n-1) x++,y=0;
                else y++;
            }
            ans.push_back(v1);
        }
        return ans;
    }
};