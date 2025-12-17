class Solution {
public:
    long long fun(int i, int k, int buy, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        int n = prices.size();
        if(k < 0) return -1e15;
        if(i == n) return buy == 1 ? 0 : -1e15;
        if(dp[i][k][buy] != -1e16) return dp[i][k][buy];
        if(buy) {
            long long a = -prices[i] + fun(i + 1, k, 0, prices, dp);
            long long b = fun(i + 1, k, 1, prices, dp);
            return dp[i][k][buy] = max(a, b);
        } else {
            long long a = prices[i] + fun(i + 1, k - 1, 1, prices, dp);
            long long b = fun(i + 1, k, 0, prices, dp);
            return dp[i][k][buy] = max(a, b);
        }
    }
    long long maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (k + 1, vector<long long> (2, -1e16)));
        return fun(0, k, 1, prices, dp);
    }
};