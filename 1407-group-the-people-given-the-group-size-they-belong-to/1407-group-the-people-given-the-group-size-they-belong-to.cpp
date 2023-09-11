class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, vector<int>> t;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            int j = nums[i];
            t[j].push_back(i);
            if(t[j].size() == j)
            {
                ans.push_back(t[j]);
                t[j].clear();
            }
        }
        return ans;
    }
};