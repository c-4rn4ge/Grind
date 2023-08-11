class Solution 
{
	int solve(int i , int sum , vector<int> &a , vector<vector<int>> & dp)
    {
		if(i == a.size()) 
        {
			if(sum == 0) return 1;
			return 0;
		}
		if(dp[i][sum] != -1) return dp[i][sum];
		int ans = solve(i + 1, sum , a,dp);
		if(a[i] <= sum) ans += solve(i , sum - a[i] , a,dp);
		return dp[i][sum] = ans;
	}
public:
	int change(int k, vector<int>& a) 
    {
		vector<vector<int>> dp(a.size() , vector<int>(k+1,-1));
		int ans = solve(0,k,a,dp);
		return ans;
	}
};