class Solution {
public:
    int fun(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if(i == 0) {
            if(amount % coins[i] == 0) return 1;
            return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int p = 0;
        if(amount - coins[i] >= 0) p = fun(coins, i, amount - coins[i], dp);
        int np = fun(coins, i - 1, amount, dp);
        return dp[i][amount] = p + np;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return fun(coins, n - 1, amount, dp);
    }
};