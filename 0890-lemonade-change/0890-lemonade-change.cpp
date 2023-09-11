class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();
        stack<int> s, s2;
        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)  s.push(5);
            if (bills[i] == 10)
            {
                if (!s.empty())
                {
                    s.pop();
                    s2.push(10);
                }
                else    return false;
            }
            if (bills[i] == 20)
            {
                if (s2.size() >= 1 && s.size() >= 1)
                {
                    s.pop();s2.pop();
                }
                else if (s2.size() == 0 && s.size() >= 3)
                {
                    s.pop();s.pop();s.pop();
                }
                else    return false;
            }
        }
        return true;
    }
};