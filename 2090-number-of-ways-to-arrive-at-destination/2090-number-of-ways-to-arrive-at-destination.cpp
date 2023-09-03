class Solution 
{
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<pair<int, int>> adj[n];
        for(auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = (1e9 + 7);
        while(!pq.empty())
        {
            long long curDis = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();
            for(auto i : adj[curNode])
            {
                int adjNode = i.first;
                long long adjDist = i.second;
                if(curDis + adjDist < dist[adjNode])
                {
                    dist[adjNode] = curDis + adjDist;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[curNode];
                }
                else if(curDis + adjDist == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[curNode]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};