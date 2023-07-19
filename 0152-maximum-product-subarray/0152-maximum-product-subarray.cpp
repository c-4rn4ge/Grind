class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i,ma=nums[0],mi=nums[0],ans=nums[0],l=nums.size();
        for(i=1;i<l;i++)
        {
            if(nums[i]<0)   swap(ma,mi);
            ma = max(nums[i],ma*nums[i]);
            mi = min(nums[i],mi*nums[i]);
            ans = max(ans,ma);
        }
        return ans;
    }
};