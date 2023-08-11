class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans;
        int dif;
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return sum;
                int m = abs(target - sum);
                if (i == 0 || m < dif)
                {
                    dif = m;
                    ans = sum;
                }
                if (sum < target)
                    j++;
                else
                    k--;
                if (ans + 1 == target || ans - 1 == target)
                    n = ans;
            }
        }
        if (n != 0)
            return n;
        else
            return ans;
    }
};