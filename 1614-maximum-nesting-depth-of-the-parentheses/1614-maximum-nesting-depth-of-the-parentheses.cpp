class Solution {
public:
    int maxDepth(string s) 
    {
        int ans = 0,count=0;
        for(auto i : s)
        {
            if( (i!='(') && (i!=')') )    continue;
            if(i=='(')   count++;
            else    ans = max(ans,count),count--;
        }
        return ans;
    }
};