class Solution {
public:
    vector<vector<int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    double fun(int r, int c, int k, int n, vector<vector<vector<double>>>& dp) {
        if(r < 0 || c < 0 || r >= n || c >= n) return 0;
        if(k == 0) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        double res = 0;
        for(int i = 0; i < 8; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            res += fun(nr, nc, k - 1, n, dp) / 8;
        }
        return dp[r][c][k] = res;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k + 1, - 1)));
        return fun(row, column, k, n, dp);
    }
};