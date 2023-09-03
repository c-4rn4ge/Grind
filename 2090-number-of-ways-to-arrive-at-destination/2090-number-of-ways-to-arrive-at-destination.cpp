class Solution 
{
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        vector<pair<int,int> >adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue< pair<long long,int>, vector<pair<long long,int>>,
        greater<pair<long long,int>> > pq;
        pq.push({0,0});
        vector<long long> dist(n,LONG_MAX);
        vector<long long> ways(n,0);
        ways[0]=1;
        dist[0]=0;
        long long mod = 1e9+7;
        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            long long curDist = a.first;
            long long curNode = a.second;
            for(auto it : adj[curNode])
            {
                long long adjnode = it.first;
                long long adjDist = it.second;
                if(curDist+adjDist==dist[adjnode]) ways[adjnode] = (ways[adjnode]+ ways[curNode]) % mod;
                else if(curDist+adjDist<dist[adjnode])
                {
                    ways[adjnode]= ways[curNode];
                    dist[adjnode] = curDist + adjDist;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return ways[n-1] % mod;
    }
};