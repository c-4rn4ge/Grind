class Solution {
public:
    void dfs(int src , int dst,vector<int> adj[],vector<int> &vis,bool &ans)
    {
        if(vis[src]) return;
        vis[src] = 1;
        if(src == dst) ans = true;
        else for(auto &j : adj[src]) dfs(j,dst,adj,vis,ans);
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        vector<int> adj[numCourses];
        for(auto &i : prerequisites)    adj[i[0]].push_back(i[1]);
        int q = queries.size();
        vector<bool> ans(q,false);
        for(int i = 0; i < q; i++)
        {
            int src = queries[i][0];
            int dst = queries[i][1];
            vector<int> vis(numCourses,0);
            bool t = false;
            dfs(src,dst,adj,vis,t) ;
            ans[i] = t;
        }
        return ans;
    }
};