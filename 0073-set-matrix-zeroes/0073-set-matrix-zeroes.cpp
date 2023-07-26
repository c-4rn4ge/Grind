class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) 
    {
        int i,j,n=mat.size(),m=mat[0].size(),row=0,col=0;
        for(i=0;i<n;i++)    if(mat[i][0]==0) row =1;
        for(i=0;i<m;i++)    if(mat[0][i]==0) col =1;
        
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[0][j]=mat[i][0]=0;
                }
            }
        }
        
       
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                if(mat[i][j]!=0)
                {
                    if(!mat[0][j] || !mat[i][0])
                    {
                        mat[i][j]=0;
                    }
                }
            }
        }
        
        if(row)
        {
            for(i=0;i<n;i++)
            {
                if(mat[i][0]!=0)    mat[i][0]=0;
            }
        }
        if(col)
        {
            for(i=0;i<m;i++)
            {
                if(mat[0][i]!=0)    mat[0][i]=0;
            }
        }
    }
};
