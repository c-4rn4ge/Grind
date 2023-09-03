class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> dist(n+1,1e9);
        vector<pair<int,int>> adj[n+1];
        for(auto &i : times)    adj[i[0]].push_back({i[1],i[2]});
        queue<pair<int,int>> que;
        que.push({k,0});
        dist[k] = dist[0] = 0;
        while(que.size())
        {
            int curNode = que.front().first;
            int curDist = que.front().second;
            que.pop();
            for(auto & i : adj[curNode])
            {
                int adjNode = i.first;
                int adjDist = i.second;
                if(adjDist + curDist < dist[adjNode])
                {
                    dist[adjNode] = adjDist + curDist;
                    que.push({adjNode,dist[adjNode]});
                }
            }
        }
        int ans = 0;
        for(auto &i : dist) 
        {
            if(i==1e9) return -1;
            ans = max(ans,i);
        }
        return ans;
    }
};