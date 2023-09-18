class Solution {
public:
    int maxArea(vector<int>& a) 
    {
        int l = 0,r = a.size()-1,  ans = 0;
        while (l < r) 
        {
            ans = max(ans, min(a[l], a[r]) * (r - l));
            (a[l] < a[r]) ? l++ : r--;
        }
        return ans;
    }
};