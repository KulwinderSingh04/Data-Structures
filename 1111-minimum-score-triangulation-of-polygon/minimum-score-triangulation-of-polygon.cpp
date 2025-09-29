class Solution {
public:
    int fun(int i, int j, vector<int>& values, vector<vector<int>>& dp) {
        if(j - i < 2) return 0;
        int n = values.size();
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++) {
            ans = min(ans, values[i] * values[j] * values[k] + fun(i, k, values, dp) + fun(k, j, values, dp));
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(0, n - 1, values, dp);
    }
};