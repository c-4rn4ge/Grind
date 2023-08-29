class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int count = 0;
        vector<int> adj[numCourses],in(numCourses,0);  
        queue<int> que;
        for(auto &i : prerequisites)
        {
            adj[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(!in[i]) que.push(i);
        }
        while(que.size())
        {
            int cur = que.front();
            que.pop();
            count++;
            for(auto &i : adj[cur])
            {
                in[i]--;
                if(!in[i]) que.push(i);
            }
        }
        return (count == numCourses) ? true : false;
    }
};