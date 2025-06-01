class Solution {
public:
    long long fun(int children, int n, int& limit, vector<vector<long long>>& dp) {
        if(children == 1) {
            if(n <= limit) return 1;
            return 0;
        }
        if(dp[children][n] != -1) return dp[children][n];
        long long mx = 0;
        for(int i = 0; i <= min(limit, n); i++) {
            mx += fun(children - 1, n - i, limit, dp);
        }
        return dp[children][n] = mx;
    }
    long long distributeCandies(int n, int limit) {
        vector<vector<long long>> dp(4, vector<long long> (n + 1, -1));
        return fun(3, n, limit, dp);
    }
};