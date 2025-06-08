class Solution {
public:
    long long fun(int idx, int k, int buy, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        int n = prices.size();
        if(idx == n) {
            if(buy == 0) return 0;
            return -1e9;
        }
        if(dp[idx][k][buy] != -1) return dp[idx][k][buy];
        if(k == 0) return 0;
        if(buy == 0) {
            long long a = -prices[idx] + fun(idx + 1, k, 1, prices, dp);
            long long b = prices[idx] + fun(idx + 1, k, 2, prices, dp);
            long long c = fun(idx + 1, k, 0, prices, dp);
            return dp[idx][k][buy] = max(a, max(b, c));
        } else if(buy == 1) {
            long long a = prices[idx] + fun(idx + 1, k - 1, 0, prices, dp);
            long long b = fun(idx + 1, k, 1, prices, dp);
            return dp[idx][k][buy] = max(a, b);
        } else {
            long long a = -prices[idx] + fun(idx + 1, k - 1, 0, prices, dp);
            long long b = fun(idx + 1, k , 2, prices, dp);
            return dp[idx][k][buy] = max(a, b);
        }
        
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (k + 1, vector<long long> (3, -1)));
        return fun(0, k, 0, prices, dp);
    }
};