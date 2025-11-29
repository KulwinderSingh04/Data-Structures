class Solution {
public:
    int fun(int lo, int hi, vector<vector<int>>& dp) {
        if(lo >= hi) return 0;
        if(dp[lo][hi] != -1) return dp[lo][hi];
        int ans = INT_MAX;
        for(int i = lo; i <= hi; i++) {
            ans = min(ans, i + max(fun(lo, i - 1, dp), fun(i + 1, hi, dp)));
        }
        return dp[lo][hi] = ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return fun(1, n, dp);
    }
};