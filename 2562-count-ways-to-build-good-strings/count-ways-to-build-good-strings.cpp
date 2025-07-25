class Solution {
public:
    int MOD = 1e9+7;
    long long fun(int len, int zero, int one, int low, int high, vector<long long>& dp) {
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];
        long long p = 0, np = 0;
        p = fun(len + zero, zero, one, low, high, dp);
        np = fun(len + one, zero, one, low, high, dp);
        return len >= low ? dp[len] = (1 + np % MOD + p % MOD) % MOD : dp[len] = (np % MOD + p % MOD) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // if(low)
        vector<long long> dp(high + 1, -1);
        return fun(0, zero, one, low, high, dp);
    }
};