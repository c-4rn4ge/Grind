class Solution
{
public:
    int minCostClimbingStairs(vector<int>& nums)
    {
        int n = nums.size(), p = nums[0] , c = nums[1],  t;
        for(int i = 2; i < n; i++)
        {
            t = nums[i] + min(c, p);
            p = c ,c = t ;
        }
        return min(p,c);
    }
};