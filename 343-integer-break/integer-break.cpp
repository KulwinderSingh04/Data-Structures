class Solution {
public:
    int fun(int n, vector<int>& dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        int res = 0;
        if(dp[n] != -1) return dp[n];
        for(int i = 1; i <= n; i++) {
            res = max(res, i * fun(n - i, dp));
        }
        return dp[n] = res;
    }
    int integerBreak(int n) {
        if(n == 2 || n == 3) return n - 1;
        vector<int> dp(n + 1, -1);
        return fun(n, dp);
    }
};