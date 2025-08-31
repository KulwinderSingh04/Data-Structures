class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    int fun(int i, int j, int d, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(i == n - 1 && j == m - 1) return 1;
        if(i >= n || j >= m) return 0;
        int res = 0;
        if(dp[i][j][d] != -1) return dp[i][j][d];
        if(grid[i][j] == 0) {
            for(int k = 0; k < 2; k++) {
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                res += fun(ni, nj, k, grid, dp);
                res %= MOD;
            }
        } else {
            if(d == 0) res += fun(i + 1, j, 1, grid, dp);
            else res += fun(i, j + 1, 0, grid, dp);
            res %= MOD;
        }
        return dp[i][j][d] = res;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (2, -1)));
        return fun(0, 0, 0, grid, dp);
    }
};