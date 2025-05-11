class Solution {
public:
    int fun(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>>& dp) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        if(i >= n || j >= m) return 1e9;
        if(i == n - 1 && j == m - 1) {
            if(dungeon[i][j] > 0) return 1;
            return 1 - dungeon[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int rWays = fun(dungeon, i, j + 1, dp);
        int dWays = fun(dungeon, i + 1, j, dp);
        if(min(rWays, dWays) - dungeon[i][j] <= 0) return dp[i][j] = 1;
        return dp[i][j] = min(rWays, dWays) - dungeon[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return fun(dungeon, 0, 0, dp);
    }
};