class Solution {
public:
    int fun(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
        int n = mat.size();
        if(i == n) return 0;
        if(dp[i][j] != -1000) return dp[i][j];
        int mn = INT_MAX;
        for(int x = max(0, j - 1); x < min(n, j + 2); x++) {
            mn = min(mn, mat[i][x] + fun(mat, i + 1, x, dp));
        }
        return dp[i][j] = mn;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n, -1000));
        for(int j = 0; j < n; j++) {
            ans = min(ans, fun(matrix, 0, j, dp));
        }
        return ans;
    }
};