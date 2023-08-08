class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
        stack<int> s;
        int i,n=h.size(),ans=0;
        for(i=0;i<=n;i++)
        {
            while(s.size() && (i == n || h[s.top()] >= h[i]))
            {
                int a = h[s.top()];
                s.pop();
                int l = (!s.size()) ? -1 : s.top();
                ans = max(ans,(i-l-1)*a);
            }
            s.push(i);
        }
        return ans;
    }
};