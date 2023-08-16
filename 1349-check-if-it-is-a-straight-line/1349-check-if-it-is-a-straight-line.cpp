class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) 
    {
        int y,x,ny,nx,i;
        y=a[1][1] - a[0][1];
        x=a[1][0] - a[0][0];
        for(i=2;i<a.size();i++)
        {
            ny=a[i][1] - a[0][1];  
            nx=a[i][0] - a[0][0];  
            if(nx * y != ny * x)    return false;
        }
        return true;
    }
};