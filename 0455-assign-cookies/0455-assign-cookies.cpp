class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int n = g.size(),m = s.size(),c = 0;
        priority_queue<int> pq,pq2;
        for (int i = 0; i < n; i++) pq.push(g[i]);
        for (int i = 0; i < m; i++) pq2.push(s[i]);
        for (int i = 0; i < g.size(); i++)
        {
            if (pq.empty() || pq2.empty()) break;
            else if(pq.top() <= pq2.top())  c++,pq.pop(),pq2.pop();
            else if(pq.top() > pq2.top()) pq.pop();
        }
        return c;
    }
};