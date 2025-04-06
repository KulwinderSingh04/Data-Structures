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
        vector<vector<uint64_t>> dp(n, vector<uint64_t> (amount + 1, -1));
        for(int a = 0; a < amount + 1; a++) {
            if(a % coins[0] == 0) dp[0][a] = 1;
            else dp[0][a] = 0; 
        }
        for(int i = 1; i < n; i++) {
            for(int a = 0; a < amount + 1; a++) {
                uint64_t p = 0;
                if(a - coins[i] >= 0) p = dp[i][a - coins[i]];
                uint64_t np = dp[i - 1][a];
                dp[i][a] = p + np;
            }
        }
        return dp[n - 1][amount];
    }
};