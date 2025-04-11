class Solution {
public:
    int fun(vector<int>& prices, int i, int buy, vector<vector<int>>& dp) {
        if(i == prices.size() - 1) {
            if(buy) return prices[i];
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 0) {
            int a = -prices[i] + fun(prices, i + 1, 1, dp);
            int b = fun(prices, i + 1, 0, dp);
            return dp[i][buy] = max(a, b);
        }
        else {
            int a = prices[i] + fun(prices, i + 1, 0, dp);
            int b = fun(prices, i + 1, 1, dp);
            return dp[i][buy] = max(a, b);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, 0));
        dp[n - 1][1] = prices[n - 1];
        dp[n - 1][0] = 0;
        for(int i = n - 2 ; i >= 0; i--) {
            for(int j = 1; j >= 0; j--) {
                if(j == 0) {
                    int a = -prices[i] + dp[i + 1][1];
                    int b = dp[i + 1][0];
                    dp[i][j] = max(a, b);
                }
                else {
                    int a = prices[i] + dp[i + 1][0];
                    int b = dp[i + 1][1];
                    dp[i][j] = max(a, b);
                }
            }
        }
        return dp[0][0];
    }
};