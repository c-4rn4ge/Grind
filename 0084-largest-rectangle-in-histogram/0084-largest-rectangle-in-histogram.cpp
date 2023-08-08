class Solution {
public:
    vector<int> nsl(vector<int> &h)
    {
        int n = h.size();
        stack<pair<int,int>> s;
        vector<int> left;
        for(int i = 0;i<n;i++)
        {
            if(!s.size()) left.push_back(-1);
            else if(s.top().first < h[i])   left.push_back(s.top().second);
            else
            {
                while(s.size() && s.top().first >= h[i]) s.pop();
                (s.size()) ? left.push_back(s.top().second) : left.push_back(-1);
            }
            s.push({h[i],i});
        }
        return left;
    }
    vector<int> nsr(vector<int> &h)
    {
        int n = h.size();
        stack<pair<int,int>> s;
        vector<int> left;
        for(int i = n-1;i>=0;i--)
        {
            if(!s.size()) left.push_back(n);
            else if(s.top().first < h[i])   left.push_back(s.top().second);
            else
            {
                while(s.size() && s.top().first >= h[i]) s.pop();
                (s.size()) ? left.push_back(s.top().second) : left.push_back(n);
            }
            s.push({h[i],i});
        }
        reverse(left.begin(),left.end());
        return left;
    }
    int largestRectangleArea(vector<int>& heights) 
    {
        vector<int> left = nsl(heights);
        vector<int> right = nsr(heights);
        for(auto i: left) cout<<i<<" ";
        cout<<endl;
        for(auto i: right) cout<<i<<" ";
        cout<<endl;
        int ans = 0;
        for(int i = 0;i<heights.size();i++)
        {
            ans = max(ans,(right[i]-left[i]-1) * heights[i]);
        }
        return ans;
    }
};