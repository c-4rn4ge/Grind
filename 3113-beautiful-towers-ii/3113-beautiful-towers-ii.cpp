class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ps(n, -1), ns(n, n);
        vector<long long> ls(n, 0), rs(n, 0);
        stack<int> s;
        ls[0] = nums[0];
        s.push(0);
        for (int i = 1; i < n; i++)
        {
            while (!s.empty() && nums[s.top()] >= nums[i])  s.pop();
            if (!s.empty()) ps[i] = s.top();
            int p = ps[i], c = i - p;
            ls[i] += (long long)c * nums[i];
            if (p != -1)    ls[i] += ls[p];
            s.push(i);
        }
        while (!s.empty())  s.pop();
        s.push(n - 1);
        rs[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            while (!s.empty() && nums[s.top()] >= nums[i])  s.pop();
            if (!s.empty()) ns[i] = s.top();
            int t = ns[i];
            int c = t - i;
            rs[i] += (long long)c * nums[i];
            if (t != n)
                rs[i] += rs[t];
            s.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            //cout << ls[i] << " " << rs[i] << endl;
            ans = max(ans, ls[i] + rs[i] - nums[i]);
        }
        return ans;
    }
};