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
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return fun(obstacleGrid, m - 1, n - 1, dp); 
    }
};