class Solution {
public:
    long long fun(int i, int k, int buy, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        int n = prices.size();
        if(k == 0) return 0;
        if(i == n) return buy == 0 ? 0 : -1e16;
        if(dp[i][k][buy] != -1e16) return dp[i][k][buy];
        if(buy == 0) {
            long long a = -prices[i] + fun(i + 1, k, 1, prices, dp);
            long long b = fun(i + 1, k, 0, prices, dp);
            long long c = prices[i] + fun(i + 1, k, 2, prices, dp);
            return dp[i][k][buy] = max({a, b, c});
        } else if(buy == 1) {
            long long a = prices[i] + fun(i + 1, k - 1, 0, prices, dp);
            long long b = fun(i + 1, k, 1, prices, dp);
            return dp[i][k][buy] = max(a, b);
        } else {
            long long c = -prices[i] + fun(i + 1, k - 1, 0, prices, dp);
            long long b = fun(i + 1, k, 2, prices, dp);
            return dp[i][k][buy] = max(b, c);   
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (k + 1, vector<long long> (3, -1e16)));
        return fun(0, k, 0, prices, dp);
    }
};