class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 1, i3 = 1, i5 = 1;
        vector<int>dp(n + 1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int d = min(dp[i2] * 2, min(dp[i3] * 3, dp[i5] * 5));
            dp[i] = d;
            if(d == dp[i2] * 2) i2++;
            if(d == dp[i3] * 3) i3++;
            if(d == dp[i5] * 5) i5++;
        }
        return dp[n];
    }
};