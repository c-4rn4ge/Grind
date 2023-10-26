class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && dp.find(arr[i] / arr[j]) != dp.end())
                {
                    dp[arr[i]] += (dp[arr[j]] * dp[arr[i] / arr[j]]);
                }
            }
        }
        long ans = 0;
        for (auto i : dp)   ans += i.second;
        return ans % (int)(1e9 + 7);
    }
};