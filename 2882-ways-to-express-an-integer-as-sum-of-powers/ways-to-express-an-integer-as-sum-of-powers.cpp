class Solution {
public:
    int MOD = 1e9+7;
    int pow(int a, int b) {
        if(b == 0) return 1;
        long long half = pow(a, b / 2);
        if(b % 2) return (half * half * a) % MOD;
        return (half * half) % MOD;
    }
    int fun(int idx, int n, int x, vector<vector<int>>& dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[idx][n] != -1) return dp[idx][n];
        int res = 0;
        for(int i = idx; pow(i, x) <= n; i++) {
            res += fun(i + 1, n - pow(i, x), x, dp);
            res %= MOD;
        }
        return dp[idx][n] = res % MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return fun(1, n, x, dp);
    }
};