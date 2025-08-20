class Solution {
public:
    int MOD = 1e9 + 7;
    int fun(int n, int absent, int late, vector<vector<vector<int>>>& dp) {
        if(n == 0) return 1;
        long long a = 0, b = 0, c = 0;
        if(dp[n][absent][late] != -1) return dp[n][absent][late];
        if(absent == 1) a = fun(n - 1, 0, 2, dp);
        if(late > 0) b = fun(n - 1, absent, late - 1, dp);
        c = fun(n - 1, absent, 2, dp);
        return dp[n][absent][late] = (a + b + c) % MOD;; 
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, - 1)));
        return fun(n, 1, 2, dp);
    }
};