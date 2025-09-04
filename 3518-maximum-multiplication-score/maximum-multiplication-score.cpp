class Solution {
public:
    long long fun(int i, int j, vector<int>& a, vector<int>& b, vector<vector<long long>>& dp) {
        int n = b.size();
        if(i == 4) return 0;
        if(j == n) return -1e15;
        if(dp[i][j] != -1e14) return dp[i][j];
        long long p = 1LL * a[i] * b[j] + fun(i + 1, j + 1, a, b, dp);
        long long np = fun(i, j + 1, a, b, dp);
        return dp[i][j] = max(np, p);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<long long>> dp(4, vector<long long> (n, -1e14));
        return fun(0, 0, a, b, dp);
    }
};