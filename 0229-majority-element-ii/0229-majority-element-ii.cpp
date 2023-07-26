class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        if(nums.size()==1) return nums;
        int i,n=nums.size(),c1=0,c2=0,ans1=INT_MIN,ans2=INT_MIN;
        vector<int> ans;
        for(i=0;i<n;i++)
        {
            if(c1==0 && nums[i]!=ans2)
            {
                ans1 = nums[i];
                c1=1;
            }
            else if(c2==0 && nums[i]!=ans1)
            {
                ans2 = nums[i];
                c2=1;
            }
            else  if(ans1 == nums[i]) c1++;
            else  if(ans2 == nums[i]) c2++; 
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
       for(i=0;i<n;i++)
       {
           if(nums[i]==ans1) c1++;
           if(nums[i]==ans2) c2++;
       }
       int t = (int)(n/3) + 1;
       if(c1>=t) ans.push_back(ans1);
       if(c2>=t) ans.push_back(ans2);
       return ans;
    }
};