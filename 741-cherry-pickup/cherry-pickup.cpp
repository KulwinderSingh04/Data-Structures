class Solution {
public:
    int fun(int i1, int j1, int i2, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        if(i1 == n - 1 && j1 == n - 1) return grid[i1][j1];
        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];
        int ans = -1e9;
        if(i1 == i2 && j1 == j2) {
            int a = grid[i1][j1];
            if(i1 + 1 < n && i2 + 1 < n && grid[i1 + 1][j1] != -1 && grid[i2 + 1][j2] != -1) ans = max(ans, a + fun(i1 + 1, j1, i2 + 1, j2, grid, dp));
            if(i1 + 1 < n && j2 + 1 < n && grid[i1 + 1][j1] != -1 && grid[i2][j2 + 1] != -1) ans = max(ans, a + fun(i1 + 1, j1, i2, j2 + 1, grid, dp));
            if(j1 + 1 < n && i2 + 1 < n && grid[i1][j1 + 1] != -1 && grid[i2 + 1][j2] != -1) ans = max(ans, a + fun(i1, j1 + 1, i2 + 1, j2, grid, dp));
            if(j1 + 1 < n && j2 + 1 < n  && grid[i1][j1 + 1] != -1 && grid[i2][j2 + 1] != -1) ans = max(ans, a + fun(i1, j1 + 1, i2, j2 + 1, grid, dp));
            return dp[i1][j1][i2] = ans;
        } else {
            int a = grid[i1][j1] + grid[i2][j2];
            if(i1 + 1 < n && i2 + 1 < n && grid[i1 + 1][j1] != -1 && grid[i2 + 1][j2] != -1) ans = max(ans, a + fun(i1 + 1, j1, i2 + 1, j2, grid, dp));
            if(i1 + 1 < n && j2 + 1 < n && grid[i1 + 1][j1] != -1 && grid[i2][j2 + 1] != -1) ans = max(ans, a + fun(i1 + 1, j1, i2, j2 + 1, grid, dp));
            if(j1 + 1 < n && i2 + 1 < n && grid[i1][j1 + 1] != -1 && grid[i2 + 1][j2] != -1) ans = max(ans, a + fun(i1, j1 + 1, i2 + 1, j2, grid, dp));
            if(j1 + 1 < n && j2 + 1 < n  && grid[i1][j1 + 1] != -1 && grid[i2][j2 + 1] != -1) ans = max(ans, a + fun(i1, j1 + 1, i2, j2 + 1, grid, dp));
            return dp[i1][j1][i2] = ans;
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n, -1)));
        int t = fun(0, 0, 0, 0, grid, dp);
        return t < -1e5 ? 0 : t;
    }
};