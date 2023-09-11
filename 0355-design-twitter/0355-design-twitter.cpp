class Twitter
{
public:
    int time;
    unordered_map<int, vector<int>> fMap;
    unordered_map<int, vector<int>> tMap;
    priority_queue<pair<int, pair<int, int>>> pq;
    Twitter()
    {
        int time = 0;
    }
    void postTweet(int id, int tweetId)
    {
        time++;
        tMap[id].push_back(tweetId);
        pq.push({time, {id, tweetId}});
    }
    vector<int> getNewsFeed(int id)
    {
        vector<int> feed;
        vector<pair<int, pair<int, int>>> v;
        while (!pq.empty() && feed.size() < 10)
        {
            v.push_back(pq.top());
            if (pq.top().second.first == id)
            {
                feed.push_back(pq.top().second.second);
            }
            else if (find(fMap[id].begin(), fMap[id].end(), pq.top().second.first) != fMap[id].end())
            {
                feed.push_back(pq.top().second.second);
            }
            pq.pop();
        }
        for (int i = 0; i < v.size(); i++)
        {
            pq.push(v[i]);
        }
        return feed;
    }

    void follow(int frId, int feId)
    {
        fMap[frId].push_back(feId);
    }

    void unfollow(int frId, int feId)
    {
        vector<int> prevF(fMap[frId]);
        if (find(prevF.begin(), prevF.end(), feId) == prevF.end())
        {
            return;
        }
        vector<int> follow;
        for (int i = 0; i < prevF.size(); i++)
        {
            if (prevF[i] != feId)
            {
                follow.push_back(prevF[i]);
            }
        }
        fMap[frId] = follow;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(id,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(id);
 * obj->follow(frId,feId);
 * obj->unfollow(frId,feId);
 */