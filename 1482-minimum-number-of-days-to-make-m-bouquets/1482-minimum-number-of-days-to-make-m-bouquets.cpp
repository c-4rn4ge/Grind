class Solution {
public:
    bool possible(vector<int> &b, int day, int m, int k) 
    {
        int n = b.size(); 
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] <= day) {
                cnt++;
            }
            else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    int minDays(vector<int>& b, int m, int k) 
    {
        long long val = m * 1ll * k * 1ll;
        int n = b.size(); 
        if (val > n) return -1; 
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, b[i]);
            maxi = max(maxi, b[i]);
        }
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(b, mid, m, k)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};

