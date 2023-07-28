class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low =0,high = nums.size()-1,minN=INT_MAX;
        while(low<=high)
        {
            int mid = low + (high -low)/2;
            if(nums[mid] < nums[low]) minN = min(minN,nums[mid]),high = mid-1;
            else minN = min(minN,nums[low]),low = mid+1;
        }
        return minN;
    }
};