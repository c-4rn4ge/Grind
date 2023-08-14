class Solution {
public:
    int findCircleNum(vector<vector<int>>& edges) 
    {
        return findNumOfProvinces(edges,edges.size());
    }
    void dfs(vector<vector<int>> &mat, int i, int n, vector<int> &v) 
    {
        if(i>=n || v[i])  return;
        v[i] = 1;
        for(int j = 0;j<n;j++)
        {
            if(i!=j && mat[i][j])
            {
            dfs(mat, j, n, v);
            }
        }
    }
    int findNumOfProvinces(vector<vector<int>> &roads, int n) 
    {
        vector<int> vis(n,0);int ans = 0;
        for (int i = 0; i < n; i++) 
        {
            if (!vis[i]) 
            {
            dfs(roads, i, n, vis);
            ans++;
            }
        }
        return ans;
    }
};