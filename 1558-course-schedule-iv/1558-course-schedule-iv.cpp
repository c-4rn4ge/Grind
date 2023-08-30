class Solution
{
public:
    void dfs(vector<vector<int>> &adj, int u, vector<bool> &vis)
    {
        for (auto &v : adj[u])
        {
            if (vis[v])    continue;
            vis[v] = true;
            dfs(adj, v, vis);
        }
    }
    vector<bool> checkIfPrerequisite(int n,vector<vector<int>> &prerequisites,vector<vector<int>> &queries)
    {
        vector<bool> ans;
        vector<vector<int>> adj(n);
        vector<vector<bool>> isPrerequisite(n, vector<bool>(n));

        for (auto &j : prerequisites)   adj[j[0]].push_back(j[1]);
        for (int i = 0; i < n; ++i) dfs(adj, i, isPrerequisite[i]);
        for (auto &i : queries)
        {
            int u = i[0];
            int v = i[1];
            ans.push_back(isPrerequisite[u][v]);
        }
        return ans;
    }
};