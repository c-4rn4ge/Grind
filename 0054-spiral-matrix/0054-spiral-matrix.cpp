class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int i,n= matrix.size(),m=matrix[0].size(),row = 0,col=0,k=1;
        vector<int> ans;char ch='r';
        for(i=0;i < n*m ;i++)
        {
            ans.push_back(matrix[row][col]);
            if(ch=='r')
            {
               if(col==m-k) ch='d',row++;
               else col++;
            }
            else if(ch=='d')
            {
               if(row==n-k) ch='l',col--;
               else row++;
            }
            else if(ch=='l')
            {
               if(col==k-1) ch='u',row--,k++;
               else col--;
            }
            else
            {
               if(row==k-1) ch='r',col++;
               else row--;
            }
        }
        return ans;
    }
};