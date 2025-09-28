class Solution {
public:
    long long fun(int i, vector<int>& cost, vector<long long>& dp) {
        int n = cost.size();
        if(i == n - 1) return 0;
        if(dp[i + 1] != -1) return dp[i + 1];
        long long b = 1e12, c = 1e12;
        long long a = cost[i + 1] + 1 + fun(i + 1, cost, dp);
        if(i + 2 < n) b = cost[i + 2] + 4 + fun(i + 2, cost, dp);
        if(i + 3 < n) c = cost[i + 3] + 9 + fun(i + 3, cost, dp);
        return dp[i + 1] = min({a, b, c});
    }
    int climbStairs(int n, vector<int>& cost) {
        vector<long long> dp(n + 1);
        dp[n] = 0;
        for(int i = n - 2; i >= -1; i--) {
            long long b = 1e12, c = 1e12;
            long long a = cost[i + 1] + 1 + dp[i + 2];
            if(i + 2 < n) b = cost[i + 2] + 4 + dp[i + 3];
            if(i + 3 < n) c = cost[i + 3] + 9 + dp[i + 4];
            dp[i + 1] = min({a, b, c});
        }
        return dp[0];
    }
};