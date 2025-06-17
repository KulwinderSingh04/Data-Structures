class Solution {
public:
    int fun(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(i == coins.size()) {
            if(amount == 0) return 0;
            return 1e9;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int a = 1e9;
        if(amount - coins[i] >= 0) a = 1 + fun(i, amount - coins[i], coins, dp);
        int b = fun(i + 1, amount, coins, dp);
        return dp[i][amount] = min(a, b);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int ans = fun(0, amount, coins, dp);
        return ans == 1e9 ? -1 : ans;
    }
};