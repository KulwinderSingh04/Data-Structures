class Solution {
public:
    int MOD = 1e9 + 7;
    // int fun(int n, int k, vector<vector<int>>& dp) {
    //     if(k == 0) return 1;
    //     if(n == 0) return 0;
    //     if(dp[n][k] != -1) return dp[n][k];
    //     long long res = 0;
    //     for(int inv = 0; inv <= min(k, n - 1); inv++) {
    //         res += fun(n - 1, k - inv, dp);
    //         res %= MOD;
    //     }
    //     return dp[n][k] = res;
    // }
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                long long res = 0;
                for(int inv = 0; inv <= min(j, i - 1); inv++) {
                    res += dp[i - 1][j - inv];
                    res %= MOD;
                }
                dp[i][j] = res;
            }
        }
        return dp[n][k];
    }
};