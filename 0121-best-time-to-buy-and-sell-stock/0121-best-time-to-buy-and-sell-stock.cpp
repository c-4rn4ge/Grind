class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy,sell,ans=0,n=prices.size();
        buy = sell = prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<buy)   
                buy = sell = prices[i];
            else if(prices[i]>sell) 
                sell = prices[i];
            ans = max(ans,sell-buy);
        }
        return ans;
    }   
};