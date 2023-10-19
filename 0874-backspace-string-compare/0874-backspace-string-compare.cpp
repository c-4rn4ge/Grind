class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string s1,t1;
        for (auto &i : s)
        {
            if (i != '#')                               s1.push_back(i);
            else if (i == '#' and s1.length() > 0)   s1.pop_back();
        }
        for (auto &i : t)
        {
            if (i != '#')                               t1.push_back(i);
            else if (i == '#' and t1.length() > 0)   t1.pop_back();
        }
        return s1 == t1;
    }
};