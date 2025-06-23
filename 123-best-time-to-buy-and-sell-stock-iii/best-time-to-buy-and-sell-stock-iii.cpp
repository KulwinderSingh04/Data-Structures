class Solution {
public:
    int fun(int i, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(i == prices.size()) return 0;
        if(k == 0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        if(buy == 0) {
            int a = -prices[i] + fun(i + 1, !buy, k, prices, dp);
            int b = fun(i + 1, buy, k, prices, dp);
            return dp[i][buy][k] = max(a, b);
        } else {
            int a = prices[i] + fun(i + 1, !buy, k - 1, prices, dp);
            int b = fun(i + 1, buy, k, prices, dp);
            return dp[i][buy][k] = max(a, b);
        }
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return fun(0, 0, 2, prices, dp);
    }
};