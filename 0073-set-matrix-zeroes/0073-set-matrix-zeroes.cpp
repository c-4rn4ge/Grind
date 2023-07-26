class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) 
    {
        int col = 1,n = mat.size(),m=mat[0].size(),i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mat[i][j]==0) 
                {
                    mat[i][0] = 0;
                    if (j != 0)
                        mat[0][j] = 0;
                    else
                        col = 0;
                }
             }
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(mat[i][j]!=0)
                {
                    if(mat[0][j] == 0 ||mat[i][0] == 0)
                    mat[i][j] = 0;
                }
            }
        }
        if (mat[0][0] == 0) 
        {
            for (j = 0; j < m; j++)
             {
                mat[0][j] = 0;
            }   
        }
        if (col == 0) {
            for ( i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }

    }
};
