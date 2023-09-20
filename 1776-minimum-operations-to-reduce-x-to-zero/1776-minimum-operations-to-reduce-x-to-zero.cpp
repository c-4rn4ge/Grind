class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> v(2 * n + 1);
        v[0] = 0;   v[1] = nums[0];
        for (int i = 1; i < n; i++)
        {
            v[i + 1] += v[i] + nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            v[n + 1 + i] = v[n + i] + nums[i];
        }
        int ans = INT_MAX,i = 0,j = 1;
        while (j <= n+(n/2))
        {
            int diff = v[j] - v[i];
            if (diff == x && j - i <= n && ((1 <= j && 1 >= i) || (n >= i && n <= j)))
            {
                ans = min(ans, j - i);
                i++;
            }
            else if (diff < x)  j++;
            else    i++;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};