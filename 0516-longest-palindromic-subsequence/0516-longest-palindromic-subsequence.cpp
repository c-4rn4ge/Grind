class Solution {
private:
    int rec(int i, int j, string& s, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i-j == 1) {
            if(s[i]==s[j]) return 2;
            else return 0;
        }
        if(i==j) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = 2 + rec(i+1, j-1, s, dp);
        else return dp[i][j] = max(rec(i+1, j, s,dp), rec(i, j-1, s, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n==1) return 1;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return rec(0, n-1, s, dp);
    }
};