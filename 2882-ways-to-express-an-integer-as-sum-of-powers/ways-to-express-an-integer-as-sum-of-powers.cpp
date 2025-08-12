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
        if(idx > n) return 0;
        if(n < 0) return 0;
        if(dp[idx][n] != -1) return dp[idx][n];
        int res = 0;
        res += fun(idx + 1, n - pow(idx, x), x, dp);
        res += fun(idx + 1, n, x, dp);
        return dp[idx][n] = res % MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return fun(1, n, x, dp);
    }
};