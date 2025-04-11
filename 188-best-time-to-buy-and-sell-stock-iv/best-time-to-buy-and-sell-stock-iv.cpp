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
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (cap + 1, -1)));
        return fun(prices, 0, 0, cap, dp);
    }
};