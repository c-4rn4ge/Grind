class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) 
    {
        int i,j,n=a.size();
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        for(i=0;i<n;i++)
        {
            if(ans.empty() || ans.back()[1] < a[i][0]) ans.push_back(a[i]);
            else ans.back()[1] = max( ans.back()[1],a[i][1]);
        }
        return ans;
    }
};