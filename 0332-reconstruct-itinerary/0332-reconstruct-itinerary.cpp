class Solution 
{
public:
    bool solve(unordered_map<string, vector<string>>& adj, vector<string>& ans, string s, int n) 
    {
        if (ans.size() == n + 1)    return true;
        if (adj[s].size() == 0)  return false;
        for (int i = 0; i < adj[s].size(); i++) 
        {
            string t = adj[s][i];
            ans.push_back(t); 
            adj[s].erase(adj[s].begin() + i); 
            if (solve(adj, ans, t, n))   return true; 
            adj[s].insert(adj[s].begin() + i, t);
            ans.pop_back();
        }
        return false; 
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        int n = tickets.size();
        sort(tickets.begin(), tickets.end()); 
        unordered_map<string, vector<string>> adj; 
        for (int i = 0; i < n; i++) 
        {
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }
        vector<string> ans; 
        ans.push_back("JFK");
        solve(adj, ans, "JFK", n);
        return ans; 
    }
};