class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int fun(int m, int n, int k, int r, int c, vector<vector<vector<int>>>& dp) {
        if(r == -1 || r == m || c == -1 || c == n) return 1;
        if(k == 0) return 0;
        if(dp[k][r][c] != -1) return dp[k][r][c];
        long long res = 0;
        for(int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            res += fun(m, n, k - 1, nr, nc, dp);
            res %= MOD;
        }
        return dp[k][r][c] = res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>> (m, vector<int> (n, -1)));
        return fun(m, n, maxMove, startRow, startColumn, dp);
    }
};