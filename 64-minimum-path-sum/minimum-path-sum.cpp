class Solution {
public:
    int fun(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 1e5;
        if(i == 0 && j == 0) return grid[0][0];
        if(dp[i][j] != -1) return dp[i][j];
        int a = fun(grid, i - 1, j, dp);
        int b = fun(grid, i, j - 1, dp);
        return dp[i][j] = grid[i][j] + min(a, b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                int a = 1e5;
                if(i - 1 >= 0) a = dp[i - 1][j];
                int b = 1e5;
                if(j - 1 >= 0) b = dp[i][j - 1];
                dp[i][j] = grid[i][j] + min(a, b);
            }
        }
        return dp[m - 1][n - 1];
    }
};