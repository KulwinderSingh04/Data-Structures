class Solution {
public:
    int fun(vector<vector<int>>& grid, int sr, int sc, vector<vector<int>>& dp) {
        if(sr < 0 || sc < 0  || grid[sr][sc] == 1) return 0;
        if(sr == 0 && sc == 0) return 1;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        return dp[sr][sc] = fun(grid, sr - 1, sc, dp) + fun(grid, sr, sc - 1, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = 1;
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) { 
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    if(i == 0 && j == 0) continue;
                    int a = 0, b = 0;
                    if(i - 1 >= 0) a = dp[i - 1][j];
                    if(j - 1 >= 0) b = dp[i][j - 1];
                    // cout << a << " " << b << endl;
                    dp[i][j] = a + b;
                }
            }
            // cout << endl;
        }
        return dp[m - 1][n - 1]; 
    }
};