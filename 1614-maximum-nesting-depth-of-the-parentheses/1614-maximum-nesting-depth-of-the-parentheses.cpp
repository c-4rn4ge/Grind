class Solution {
public:
    int maxDepth(string s) 
    {
        int ans = 0,i,l = s.length(),count=0;
        for(i=0;i<l;i++)
        {
            if( (s[i]!='(') && (s[i]!=')') )    continue;
            if(s[i]=='(')   count++;
            else    ans = max(ans,count),count--;
        }
        return ans;
    }
};