class Solution {
public:
    int trap(vector<int>& h) 
    {
        int n = h.size();
        int le[n],ri[n],i,sum=0;
        le[0] = h[0],ri[n-1] = h[n-1];
        for(i=1;i<n;i++) le[i] = max(le[i-1] ,h[i]);
        for(i=n-2;i>=0;i--) ri[i] = max(ri[i+1] ,h[i]);
        for(i=0;i<n;i++) sum += min(le[i],ri[i]) - h[i];
        return sum;
    }
};