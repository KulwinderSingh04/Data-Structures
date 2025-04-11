class Solution {
public:
    int fun(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>& dp) {
        if(cap == 0) return 0;
        if(i == prices.size() - 1) {
            if(buy) return prices[i];
            return 0;
        }
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if(buy == 0) {
            int a = -prices[i] + fun(prices, i + 1, 1, cap, dp);
            int b = fun(prices, i + 1, 0, cap, dp);
            return dp[i][buy][cap] = max(a, b);
        }
        else {
            int a = prices[i] + fun(prices, i + 1, 0, cap - 1, dp);
            int b = fun(prices, i + 1, 1, cap, dp);
            return dp[i][buy][cap] = max(a, b);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int cap = k;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (cap + 1, 0)));
        for(int i = n - 1 ; i >= 0; i--) {
            for(int j = 1; j >= 0; j--) {
                for(int k = 0; k <= cap; k++) {
                    if(k == 0) dp[i][j][k] = 0;
                    else if(i == n - 1) {
                        if(j == 1) dp[i][j][k] = prices[i];
                        else dp[i][j][k] = 0;
                    }
                    else {
                        if(j == 0) {
                            int a = -prices[i] + dp[i + 1][1][k];
                            int b = dp[i + 1][0][k];
                            dp[i][j][k] = max(a, b);
                        }
                        else {
                            int a = prices[i] + dp[i + 1][0][k - 1];
                            int b = dp[i + 1][1][k];
                            dp[i][j][k] = max(a, b);
                        }
                    }
                }
            }
        }
        return dp[0][0][cap];
    }
};