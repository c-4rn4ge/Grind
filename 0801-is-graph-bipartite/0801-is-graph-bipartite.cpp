class Solution 
{
private: 
    bool bfs(vector<vector<int>> &graph,vector<int> &color,int node,int n)
    {
        color[node] = 0;
        queue<int> que;
        que.push(node);
        while(!que.empty())
        {
            int curNode = que.front();
            que.pop();
            for(auto &i : graph[curNode])
            {
                if(color[i]==-1)
                {
                    que.push(i);
                    color[i] = !color[curNode];
                }
                else if(color[i] == color[curNode])
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i = 0 ; i < n ; i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(graph,color,i,n)) return false;
            }
        }
        return true;
    }
};