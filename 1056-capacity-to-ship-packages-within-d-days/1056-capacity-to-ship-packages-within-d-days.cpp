class Solution {
public:
    bool system(vector<int>& nums ,int d,int w)
    {
        int sum = 0,ans=0;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            if(sum==w) sum = 0,ans++;
            else if(sum > w)
            {
                sum = nums[i];
                ans++;
            }
            if(ans > d) return false;
        }
        if(sum > 0) ans++;
        if(ans <= d) return true;
        return false;
    }
    int shipWithinDays(vector<int>& nums, int d) 
    {
        int sum=0,maxi=INT_MIN;
        for(auto i : nums) sum += i,maxi = max(maxi,i);
        int l = maxi,h=sum;
        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(system(nums,d,m)) h=m-1;
            else l = m+1;
        }
        return l;
    }
};