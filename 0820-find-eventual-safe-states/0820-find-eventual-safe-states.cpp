class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> adj[n],in(n,0),ans;
        queue<int> que;
        for(int i = 0 ; i < n; i++)
        {
            for(auto &j : graph[i])
            {
                adj[j].push_back(i);
                in[i]++;
            }
        }
        for(int i = 0 ; i < n ; i++) if(!in[i]) que.push(i);
        while(que.size())
        {
            int cur = que.front();
            que.pop();
            ans.push_back(cur);
            for(auto &i : adj[cur])
            {
                in[i]--;
                if(!in[i]) que.push(i); 
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};