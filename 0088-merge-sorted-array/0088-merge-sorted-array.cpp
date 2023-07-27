class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) 
    {
        int i=0,j=0;
        vector<int> res;
        while(i<m && j<n)
        {
            if(a[i]<b[j])
                res.push_back(a[i++]);
            else if(a[i]>b[j])
                res.push_back(b[j++]);
            else 
            {
                res.push_back(a[i++]);
                res.push_back(b[j++]);
            }
        }
        while(i<m||j<n)
        {
            if(i<m) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }
        for(i=0;i<m+n;i++)
        {
            a[i]=res[i];
        }
    }
};