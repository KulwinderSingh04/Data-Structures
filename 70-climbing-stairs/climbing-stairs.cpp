class Solution {
public:
    int fun(int n, vector<int>& dp) {
        if(n == 2 || n == 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fun(n - 1, dp) + fun(n - 2, dp);
    }
    int climbStairs(int n) {
        vector<long long int> dp(n + 1);
        dp[1] = 1;
        if(n + 1 > 2) dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};