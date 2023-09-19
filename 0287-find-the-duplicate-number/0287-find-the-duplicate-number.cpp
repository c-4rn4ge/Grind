class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL) ;
        int f = 0;
        int s = 0;

        while (true){
            f = nums[nums[f]];
            s = nums[s];
            if(s == f){break;}
        }

        f = 0;
        while(true){
            f = nums[f];
            s = nums[s];
            if(f == s){return s;}
        }
    }
};