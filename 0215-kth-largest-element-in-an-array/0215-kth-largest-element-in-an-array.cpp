class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if(nums.size() == 1)    return nums[0];
        priority_queue<int,vector<int>,greater<int>> mnheap;
        for( int i = 0; i < k ; i ++)
        {
            int element = nums[i];
            mnheap.push(element);
        }
        for(int i = k; i < nums.size() ; i ++)
        {
            int element = nums[i];
            if(element > mnheap.top())
            {
                mnheap.pop();
                mnheap.push(element);
            }
        }
        int ans = mnheap.top();
        return ans;
    }
};