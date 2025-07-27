class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isSafe(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    int solve(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int ans = 0;
        if(dp[r][c] != -1) return dp[r][c];
        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(isSafe(nr, nc, grid) && grid[nr][nc] > grid[r][c]) {
                ans += solve(nr, nc, grid, dp);
                ans %= MOD;
            }
        }
        return dp[r][c] = 1 + ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long res = 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res += solve(i, j, grid, dp);
                res %= MOD;
            }
        }
        return res;
    }
};