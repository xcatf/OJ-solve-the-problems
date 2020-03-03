class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(!k || prices.empty()) return 0;
        int n = prices.size();
        if(k >= n / 2){
            int ans = 0;
            for(int i = 1; i < n; ++i){
                if(prices[i] > prices[i - 1]) ans += prices[i] - prices[i - 1];
            }
            return ans;
        }
        vector<int> dp(2*k,INT_MIN);
        dp[0] = -prices[1];
        for(int i = 1; i < n; ++i){
            dp[0] = max(dp[0], -prices[i]);
            for(int j = 1; j < 2 * k; ++j){
                if(j & 1) dp[j] = max(dp[j], dp[j] + prices[i]);
                else dp[j] = max(dp[j], dp[j] - prices[i]);
            }
        }
    }
};