class Solution {
public:
    bool system(vector<int> &nums,int n,int t,int div)
    {
        double a;
        long long int sum=0;
        for(int i=0;i<n;i++)
        {
            a = (double)nums[i]/div;
            sum += ceil(a);
        }
        if((int)sum<=t) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int t) 
    {
        int maxi = INT_MIN;
        for(auto i : nums) maxi = max(maxi,i);
        int l=1,h=maxi,n=nums.size();
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(system(nums,n,t,m)) h = m-1;
            else l = m+1;
        }
        return l;
    }
};