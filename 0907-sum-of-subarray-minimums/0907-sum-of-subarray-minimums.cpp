class Solution 
{
public:
    int mod = 1e9+7;
    vector<int> prevBound(vector<int> &arr) 
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0;i < n; i++) 
        {
            while(!st.empty() && arr[st.top()] >= arr[i])   st.pop();   
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextBound(vector<int> &arr) 
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1;i >= 0; i--) 
        {
            while(!st.empty() && arr[st.top()] > arr[i])    st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) 
    {
        vector<int> prevMin = prevBound(arr);
        vector<int> nextMin = nextBound(arr);
        long long int sum = 0;
        for(int i = 0;i < arr.size(); i++) 
        {
            long long int leftMin = i-prevMin[i];
            long long int rightMin = nextMin[i]-i;
            sum = (sum+1ll*arr[i]*leftMin*rightMin)%mod;
        }

        return sum;
    }
};