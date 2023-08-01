class Solution {
public:
    void moveZeroes(vector<int>& a) 
    {
        int n = a.size(),low = 0,high=1;
        while(low < n && high < n)
        {
            if(a[low]) {low ++;high = low+1;}
            else if(a[low]==0 && a[high]==0) high++;
            else if(a[low]==0 && a[high]) swap(a[low++],a[high]);
        }
    }
};