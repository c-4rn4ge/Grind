class Solution {
public:
    int solve(int n,vector<int> &h)
    {
        if(n == 0 || n == 1) return 1;
        if(h[n]!=-1) return h[n];
        return h[n] = solve(n-1,h) + solve(n-2,h);
    }
    int climbStairs(int n) 
    {
        vector<int> h(n+1,-1);
        return solve(n,h);
    }
};
