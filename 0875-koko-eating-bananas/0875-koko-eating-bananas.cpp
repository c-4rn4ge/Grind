class Solution {
public:
    int system(vector<int>& piles, int n,int x,int h)
    {
        int i;
        long long int sumofhours = 0;
        double a;
        for(i=0;i<n;i++)
        {
            a = (double)piles[i]/x;
            sumofhours += ceil(a);
        }
        if(sumofhours <= h) return sumofhours;
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        long long int i,n=piles.size(),j=1,maxi=0;
        if(n==1) return ceil((double)piles[0] / h);
        for(i=0;i<n;i++) if(maxi<piles[i]) maxi=piles[i];
        int l=1,hi=maxi;
        while(l<=hi)
        {
            int m = l + (hi-l)/2;
            if(system(piles,n,m,h))
            {
                hi = m-1;
            }
            else l  = m+1;
        }
        return l;
    }
};