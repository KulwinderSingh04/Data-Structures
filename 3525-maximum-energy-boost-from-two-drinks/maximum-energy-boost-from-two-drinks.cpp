class Solution {
public:
    long long fun(int i, int turn, vector<int>& a, vector<int>& b, vector<vector<long long>>& dp) {
        int n = a.size();
        if(i >= n) return 0;
        if(dp[i][turn] != -1) return dp[i][turn];
        long long ans = 0;
        if(turn) {
            ans = a[i] + fun(i + 1, turn, a, b, dp);
            ans = max(ans, a[i] + fun(i + 2, !turn, a, b, dp));
            return dp[i][turn] = ans;
        } else {
            ans = b[i] + fun(i + 1, turn, a, b, dp);
            ans = max(ans, b[i] + fun(i + 2, !turn, a, b, dp));
            return dp[i][turn] = ans;
        }
    }
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<long long>> dp(n, vector<long long> (2, -1));
        return max(fun(0, 0, a, b, dp), fun(0, 1, a, b, dp));
    }
};