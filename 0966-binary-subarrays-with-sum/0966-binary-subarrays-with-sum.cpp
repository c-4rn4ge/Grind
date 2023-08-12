class Solution 
{
public:
    int numSubarraysWithSum(vector<int>& nums, int k) 
    {
        int j = 0, odd = 0, count = 0, total = 0,i=0;
        if(k==0)
        {
            while(j<nums.size())
            {
                while(i<=j && nums[j])
                {
                    i++;
                }
                total+=j-i+1;
                j++;
            }
            return total;
        }
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] == 1) 
            {
                odd++;
                if (odd >= k) 
                {
                    count = 1;
                    while (nums[j++] == 0) count++;
                    total += count;
                }
            } 
            else if (odd >= k) total += count;
        }
        return total;
    }
};