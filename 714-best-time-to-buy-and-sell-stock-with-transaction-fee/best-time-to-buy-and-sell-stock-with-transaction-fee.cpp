class Solution {
public:
    int fun(int i, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        int n = prices.size();
        if(i == n) return 0;
        int profit = 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy) {
            int a = -prices[i] - fee + fun(i + 1, 0, prices, fee, dp);
            int b = fun(i + 1, 1, prices, fee, dp);
            profit = max(a, b);
        }
        else {
            int a = prices[i]  + fun(i + 1, 1, prices, fee, dp);
            int b = fun(i + 1, 0, prices, fee, dp);
            profit = max(a, b);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return fun(0, 1, prices, fee, dp);
    }
};