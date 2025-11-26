class Solution {
public:
    int MOD = 1e9 + 7;
    int fun(int r, int c, int sum, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if(r >= n || c >= m) return 0;
        sum += grid[r][c];
        if(r == n - 1 && c == m - 1) return sum % k == 0;
        sum %= k;
        if(dp[r][c][sum] != -1) return dp[r][c][sum];
        int ans = 0;
        int a = fun(r + 1, c, sum % k, k, grid, dp);
        int b = fun(r, c + 1, sum % k, k, grid, dp);
        // cout << a << " " << b << endl;
        return dp[r][c][sum] = (a + b) % MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k + 1, -1)));
        return fun(0, 0, 0, k, grid, dp);
    }
};