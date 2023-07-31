class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int k) 
    { 
        int row = a.size(),col=a[0].size(),l=0,h = (row*col) -1;
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(a[m/col][m%col] == k) return true;
            else if(a[m/col][m%col] > k) h = m-1;
            else l = m+1;
        }
        return false;
    }
};