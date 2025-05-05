class Solution {
public:
    int MOD = 1e9+7;
    long long fun(int n, vector<long long>& dp) {
        if(n <= 2) return n;
        if(n == 3) return 5;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (2 * fun(n - 1, dp) + fun(n - 3, dp)) % MOD;
    }
    int numTilings(int n) {
        vector<long long> dp(n + 1, -1);
        return fun(n, dp) % MOD;
    }
};