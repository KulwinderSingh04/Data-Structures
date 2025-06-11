class Solution {
public:
    int fun(int i1, int j1, int i2, int j2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
        int n = grid.size();
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) return INT_MIN;
        if(i1 == n - 1 && j1 == n - 1) return grid[i1][j1] != -1 ? grid[i1][j1] : INT_MIN;
        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];
        int c1 = fun(i1 + 1, j1, i2 + 1, j2, grid, dp);
        int c2 = fun(i1 + 1, j1, i2, j2 + 1, grid, dp);
        int c3 = fun(i1, j1 + 1, i2 + 1, j2, grid, dp);
        int c4 = fun(i1, j1 + 1, i2, j2 + 1, grid, dp);

        if(i1 == i2 && j1 == j2) {
            if(grid[i1][j1] == 1) return dp[i1][j1][i2][j2] = 1 + max(max(c1, c2), max(c3, c4));
            else return dp[i1][j1][i2][j2] = max(max(c1, c2), max(c3, c4));
        } else {
            if(grid[i1][j1] == 1 && grid[i2][j2] == 1) return dp[i1][j1][i2][j2] = 2 + max(max(c1, c2), max(c3, c4));
            else if(grid[i1][j1] == 1 || grid[i2][j2] == 1) return dp[i1][j1][i2][j2] =  1 + max(max(c1, c2), max(c3, c4)); 
            else return dp[i1][j1][i2][j2] = max(max(c1, c2), max(c3, c4));
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>> (n, vector<vector<int>> (n, vector<int> (n, -1))));
        int ans = fun(0, 0, 0, 0, grid, dp);
        return ans < 0 ? 0 : ans;
    }
};