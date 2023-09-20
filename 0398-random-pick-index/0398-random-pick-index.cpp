class Solution 
{
public:
    
    vector<int> arr;
    
    Solution(vector<int>& nums) 
    {
        arr = nums;
    }
    
    int pick(int target) 
    {
        int  c = 0, ans = 0,n = arr.size();
        for (int i = 0; i < n; i++) 
        {
            if (arr[i] == target) 
            {
                c++;
                if (rand() % c == 0)    ans = i;
            }
        }
        return ans;
    }
};