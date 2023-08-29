class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses],in(numCourses,0),ans;  
        queue<int> que;
        for(auto &i : prerequisites)
        {
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(!in[i]) que.push(i);
        }
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
        return (ans.size() == numCourses) ? ans : vector<int>{};        
    }
};