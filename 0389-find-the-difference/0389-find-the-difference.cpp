class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        int c = 0;
        for(auto &i : s) c ^= i;
        for(auto &i : t) c ^= i;
        return (char)c;
    }
};