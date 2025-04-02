class Solution {
public:
    int fun(int sr, int sc, vector<vector<int>>& dp) {
        if(sr == 0 && sc == 0) return 1;
        if(sr < 0 || sc < 0) return 0;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        return dp[sr][sc] = fun(sr - 1, sc, dp) + fun(sr, sc - 1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if( i == 0 && j == 0) continue;
                int a = 0;
                if(i - 1 >= 0) a = dp[i - 1][j];
                int b = 0;
                if(j - 1 >= 0) b = dp[i][j - 1];
                dp[i][j] = a + b;
            }
        }
        return dp[m - 1][n - 1];
    }
};