class Solution {
public:
    int fun(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return INT_MIN;
        if(i == n) return 0;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int cherries = 0;
        if(j1 == j2) cherries += grid[i][j1];
        else {
            cherries += grid[i][j1] + grid[i][j2];
        }
        int mx = 0;
        for(int k1 = -1; k1 < 2; k1++) {
            for(int k2 = -1; k2 < 2; k2++) {
                mx = max(mx, fun(i + 1, j1 + k1, j2 + k2, grid, dp));
            }
        }
        return dp[i][j1][j2] = cherries + mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        return fun(0, 0, m - 1, grid, dp);

    }
};