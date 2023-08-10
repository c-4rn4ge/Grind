class Solution 
{
private: 
    int mod=1e9+7;
    long long Min(vector<int>& nums,int n) 
    {
        ios_base::sync_with_stdio(false);
        int l;
        stack<int> st;
        long long ans=0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && ((i==n) || nums[st.top()]>nums[i]) )
            {
                int ind=st.top();
                st.pop();
                if(st.empty())  l=ind+1;
                else            l=ind-st.top();
                ans=(ans+(long long )nums[ind]*l*(i-ind));
            }
            st.push(i);
        }
        return ans;
    }
    long long Max(vector<int>& nums,int n) 
    {
        ios_base::sync_with_stdio(false);
        int l;
        stack<int> st;
        long long ans=0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && ((i==n) || nums[st.top()]<nums[i]) )
            {
                int ind=st.top();
                st.pop();
                if(st.empty())  l=ind+1;
                else            l=ind-st.top();
                ans=(ans+(long long )nums[ind]*l*(i-ind));
            }
            st.push(i);
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        long long maxi = Max(nums,nums.size());
        long long mini = Min(nums,nums.size());
        return maxi - mini;
    }
};