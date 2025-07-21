class Solution {
public:
    int fun(int n, vector<int>& dp) {
        if(n == 0) return 0;
        if(n < 0) return 1e7;
        if(dp[n] != -1) return dp[n];
        int p = 1e6;
        for(int i = 1; i <=sqrt(n); i++) {
            p = min(p, 1 + fun(n - i * i, dp));
        }
        return dp[n] = p;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return fun(n, dp);
    }
};