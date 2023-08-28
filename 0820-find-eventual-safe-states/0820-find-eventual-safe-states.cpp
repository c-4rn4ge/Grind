class Solution {
public:
    bool dfs(vector<vector<int>>& edges, vector<int> &vis,vector<int> &pathVis,int node,int v)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto &i : edges[node])
        {
            if(!vis[i])
            {
                if(dfs(edges,vis,pathVis,i,v)) return true;
            }
            else if(pathVis[i]) return true;
        }
        pathVis[node] = 0; 
        return false;
    }

    bool isCyclic(vector<vector<int>>& edges, int v, int e)
    {
        vector<vector<int>> ans(v);
        for(int i = 0;i<edges.size();i++)
        {
            int e1 = edges[i][0];
            int e2 = edges[i][1];
            ans[e1].push_back(e2);
        }
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<int> vis(v,0),pathVis(v,0);
        for(int i = 0 ; i < v ; i++)
        {
            if(!vis[i])
            {
                dfs(graph,vis,pathVis,i,v);
            }
        }
        vector<int> ans;
        for(int i = 0 ; i < v ; i++)
        {
            if(!pathVis[i]) ans.push_back(i);
        }     
        return ans;
    }
};