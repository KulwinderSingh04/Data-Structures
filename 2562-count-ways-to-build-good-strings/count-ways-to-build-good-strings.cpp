class Solution {
public:
    int MOD = 1e9+7;
    long long fun(int len, int zero, int one, int thresh, vector<long long>& dp) {
        if(len > thresh) return 0;
        if(dp[len] != -1) return dp[len];
        long long p = 0, np = 0;
        p = fun(len + zero, zero, one, thresh, dp);
        np = fun(len + one, zero, one, thresh, dp);
        return dp[len] = (1 + np % MOD + p % MOD) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        // if(low)
        vector<long long> dp1(high + 1, -1), dp2(low, -1);
        return (fun(0, zero, one, high, dp1) - fun(0, zero, one, low - 1, dp2) + MOD) % MOD;
    }
};