bool compare(pair<int, int> &x, pair<int, int> &y)
{
    return x.first < y.first;
}
void sorter(vector<pair<int, int>> &temp)
{
    sort(temp.begin(), temp.end(), compare);
}
class Solution
{
public:
    int minTaps(int n, vector<int> &nums)
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i <= n; i++)
        {
            temp.push_back(make_pair(max(0, i - nums[i]), min(n, i + nums[i])));
        }
        sorter(temp);
        vector<pair<int, int>> st;
        st.push_back(temp[0]);
        int covered = temp[0].second;
        for (int i = 1; i < n + 1; i++)
        {
            pair<int, int> &range = temp[i];
            if (range.first > st[st.size() - 1].second) return -1;
            if (st[st.size() - 1].second < range.second)
            {
                covered = range.second;
                while (true)
                {
                    if (st.size() > 1 && st[st.size() - 2].second >= range.first)
                    {
                        st.pop_back();
                    }
                    else if (st.size() == 1)
                    {
                        if (st[0].first == range.first)
                        {
                            st.pop_back();
                        }
                        st.push_back(range);
                        break;
                    }
                    else
                    {
                        st.push_back(range);
                        break;
                    }
                }
            }
        }
        return st.size();
    }
};