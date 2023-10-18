class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<vector<int>> adjList(n);
        vector<int> deg(n, 0);
        vector<int> t(n, -1);
        for (auto &i : relations)
        {
            adjList[i[1] - 1].push_back(i[0] - 1);
            deg[i[0] - 1]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 0)
            {
                q.push(i);
                t[i] = time[i];
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &j : adjList[node])
            {
                deg[j]--;
                if (!deg[j])  q.push(j);
                t[j] = max(t[j], t[node] + time[j]);
            }
        }
        int ans = 0;
        for(auto &i : t) ans = max(ans,i);
        return ans;
    }
};