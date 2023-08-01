class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int sum = 0,c=0,os,j=nums.size();
        os = j * (j+1)/2;
        for(auto i: nums)
        {
            sum += i;
            if(i==0) c++;
        }
        if(c==0) return 0;
        return os-sum;
    }
};