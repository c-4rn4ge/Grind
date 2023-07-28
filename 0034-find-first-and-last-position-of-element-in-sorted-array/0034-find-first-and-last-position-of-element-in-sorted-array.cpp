class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) 
    {
        int n = arr.size();
        int l = 0,h=n-1,ans=0,floor=-1,ceiling=-1;
        while(l<=h)
        {
            int m = l + (h-l) /2;
            if(arr[m] == x) {floor = m;l = m+1;}
            else if(arr[m]<x) l = m+1;
            else h = m-1;
        }
        l = 0;h= n-1;
        while(l<=h)
        {
            int m = l + (h-l) /2;
            if(arr[m] < x) l = m+1;
            else if( arr[m]==x){ceiling = m;h = m-1;}
            else h=m-1;
        }
        return {ceiling,floor};    
    }
};