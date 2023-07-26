class Solution {
public:
    vector<int> countFreq(vector<int>& arr, int n,int k)
    {  
        vector<int> count;
        for(int i = 0 ; i < n ;i++)
        {
          int first_index = lower_bound(arr.begin(), arr.end(), arr[i]) - arr.begin();
          int last_index =  upper_bound(arr.begin(),arr.end(),arr[i])   - arr.begin() -1;
          i=last_index;
          int fre=last_index-first_index+1;
          cout << arr[i] <<" "<<fre <<endl;
          if(fre>k) count.push_back(arr[i]);
        }
        return count;
    }
    vector<int> majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        return countFreq(nums,nums.size(),nums.size()/3);
    }
};