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
        return fun(m - 1, n - 1, dp);
    }
};