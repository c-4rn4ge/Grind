class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        vector<int> mp(26);
        for (int i = 0; i < tasks.size(); i++)  ++mp[tasks[i] - 'A'];
        for (int i = 0; i < 26; i++)    if (mp[i])    pq.push(mp[i]);
        int time = 0;
        while (q.size() || pq.size())
        {
            time++;
            if (!pq.empty())
            {
                if (pq.top() - 1)   q.push({pq.top() - 1, time + n});
                pq.pop();
            }
            if (!q.empty() && q.front().second == time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};