class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int a = nums[0], b = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)    swap(a, b);
            a = max(a * nums[i], nums[i]);
            b = min(b * nums[i], nums[i]);
            ans = max(ans, a);
        }
        return ans;
    }
};