class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int i=0,j;
        string ans;
        for( j = 0;j<strs[i].size();j++)
        {
            for( i = 0;i<strs.size()-1;i++)
            {
                if(strs[i][j]!=strs[i+1][j]) break; 
            }
            if(i==strs.size()-1) ans.push_back(strs[i][j]);
            else break;
        }
        return ans;
    }
};