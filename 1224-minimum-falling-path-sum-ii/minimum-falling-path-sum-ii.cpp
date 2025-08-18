class Solution {
public:
    int fun(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(r == n) return 0;
        if(c != -1 && dp[r][c] != -1e8) return dp[r][c];
        int res = INT_MAX;
        for(int j = 0; j < m; j++) {
            if(j == c) continue;
            res = min(res, grid[r][j] + fun(r + 1, j, grid, dp));
        }
        return c != -1 ? dp[r][c] = res : res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m));
        for(int j = 0; j < m; j++) dp[n - 1][j] = grid[n - 1][j];
        for(int i = n - 2; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                int res = INT_MAX;
                for(int k = 0; k < m; k++) {
                    if(k == j) continue;
                    res = min(res, grid[i][j] + dp[i + 1][k]);
                }
                dp[i][j] = res;
            }
        }
        int res = INT_MAX;
        for(auto x : dp[0]) res = min(res, x);
        return res;
    }
};