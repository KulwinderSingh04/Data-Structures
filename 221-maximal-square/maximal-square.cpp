class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int> (m));
        for(int i = 0; i < n; i++) if(mat[i][0] == '1') dp[i][0] = 1;
        for(int i = 0; i < m; i++) if(mat[0][i] == '1') dp[0][i] = 1;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    mx = max(mx, dp[i][j]);
                    continue;
                }
                if(mat[i][j] == '0') continue;
                dp[i][j] = 1 + min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]);
                mx = max(mx, dp[i][j]);
            }
        }
        return mx * mx;
    }
};