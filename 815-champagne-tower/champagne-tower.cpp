class Solution {
public:
    double fun(int i, int j, int poured, vector<vector<double>>& dp) {
        if(i == 0 && j == 0) {
            return poured;
        }
        if(j > i || i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        double a = max(0.0, (fun(i - 1, j, poured, dp) - 1) / 2.0);
        double b = max(0.0, (fun(i - 1, j - 1, poured, dp) - 1) / 2.0);
        return dp[i][j] = a + b;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double> (101, -1));
        double ans = fun(query_row, query_glass, poured, dp);
        return ans > 1 ? 1 : ans;
    }
};