class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if(n<4) return {};
        sort(nums.begin(),nums.end());
        long long i,j,l,r,a,b,c,d;
        vector<vector<int>> ans;
        for(i=0;i<n-3;i++)
        {
           // if (nums[i]>target) break;
            if (i>0 && nums[i] == nums[i-1]) continue;
            a = nums[i];
            for (int j=i+1;j<n-2;j++) 
            {
                //if (nums[j]>target) break;
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                b = nums[j];
                for (l=j+1,r=n-1;l<r;) 
                {
                    int c = nums[l], d = nums[r];
                    if (a+b+c+d == target) 
                    {
                        ans.emplace_back(vector<int>{(int)a,(int)b,(int)c,(int)d});++l, --r; 
                        while (l < r && nums[l] == c) ++l;
                        while (l < r && nums[r] == d) --r;
                    } 
                    else if (a+b+c+d > target) --r; 
                    else ++l;
                }
            }
        }
        return ans;
    }
};