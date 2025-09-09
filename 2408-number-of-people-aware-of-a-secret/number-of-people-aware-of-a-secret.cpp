class Solution {
public:
    int MOD = 1e9+7;
    int solve(int day, int delay, int forget, vector<int>& dp) {
        if(day == 1) return 1;
        if(dp[day] != -1) return dp[day];
        int res = 0;
        for(int d = day - forget + 1; d <= day - delay; d++) {
            if(d <= 0) continue;
            res += solve(d, delay, forget, dp);
            res %= MOD;
        }
        return dp[day] = res;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int tot = 0;
        vector<int> dp(n + 1, -1);
        for(int i = n - forget + 1; i <= n; i++) {
            if(i > 0) {
                tot += solve(i, delay, forget, dp);
                tot %= MOD;
            }
        }
        return tot;
    }
};