class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &mat)
    {
        if (mat.empty()) return 0;
        int ans = 0;
        vector<int> nums(mat[0].size(), 0);
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == '0')   nums[j] = 0;
                else                    nums[j]++;
            }
            ans = max(ans, solve(nums));
        }
        return ans;
    }
    int solve(vector<int> &nums)
    {
        stack<int> s;
        nums.push_back(0);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.empty() || nums[i] >= nums[s.top()])  s.push(i);
            else
            {
                int temp = nums[s.top()];
                s.pop();
                ans = max(ans, temp * (s.empty() ? i : i - 1 - s.top()));
                i--;
            }
        }
        return ans;
    }
};