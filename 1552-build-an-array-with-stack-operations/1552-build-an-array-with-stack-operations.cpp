class Solution
{
public:
    vector<string> buildArray(vector<int> &nums, int n)
    {
        vector<string> ans;
        int x = 1;
        int i = 0;
        while (x <= n && i < nums.size())
        {
            if (nums[i] != x)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                x++;
            }
            else
            {
                ans.push_back("Push");
                x++,i++;
            }
        }
        return ans;
    }
};