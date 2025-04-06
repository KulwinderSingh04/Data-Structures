class Solution {
public:
    int fun(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if(i == 0) {
            if(amount % coins[i] == 0) return amount / coins[i];
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int p = 1e9;
        if(amount - coins[i] >= 0) p = 1 + fun(coins, i, amount - coins[i], dp);
        int np = fun(coins, i - 1, amount, dp);
        return dp[i][amount] = min(p, np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int ans = fun(coins, n - 1, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
};