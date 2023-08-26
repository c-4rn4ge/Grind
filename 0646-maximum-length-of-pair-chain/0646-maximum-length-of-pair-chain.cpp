class Solution 
{
    static bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
    {
        return (a.second < b.second);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        vector<pair<int,int>> paire;
        for(int i = 0 ; i < pairs.size() ;i++)
        {
            paire.push_back( make_pair(pairs[i][0],pairs[i][1]) );
        }
        sort(paire.begin(),paire.end(),sortbysec);
        int ans = 1;
        int j = 0;
        for(int i = 1 ; i < paire.size() ;i++)
        {
            if(paire[j].second < paire[i].first) ans ++,j=i;
        }
        return ans;
    }
};