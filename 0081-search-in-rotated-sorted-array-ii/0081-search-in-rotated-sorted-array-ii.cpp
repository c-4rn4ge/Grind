class Solution {
public:
    bool search(vector<int>& arr, int target) 
    {
        int n = arr.size();
        int low = 0, high = n-1;
        long int mid = -1;
        while(low <= high)
        {
            mid = low + (high-low)/2;
            if(arr[mid] == target || arr[low] == target || arr[high]==target) return  true;
            if(arr[mid]==arr[low] && arr[low]==arr[high]) {low++,high--;continue;}
            if(arr[mid] >= arr[low])
            {
                if(target >= arr[low] && target <= arr[mid]) high = mid-1;
                else low = mid+1;
            }
            else
            {
                if( target >= arr[mid] && target <= arr[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};