class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        if(n==1) return {{1}};
        if(n==2) return {{1},{1,1}};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        for(int i=2;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i) temp.push_back(1);
                else {int t = ans[i-1][j-1]+ans[i-1][j];temp.push_back(t);}
            }
            ans.push_back(temp);
        }
        return ans;
    }
};