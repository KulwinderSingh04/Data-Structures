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
        vector<vector<int>> dp(n, vector<int> (m));
        if(dungeon[n - 1][m - 1] > 0) dp[n - 1][m - 1] = 1;
        else dp[n - 1][m - 1] = 1 - dungeon[n - 1][m - 1];
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                int a = 1e9;
                int b = 1e9;
                if(i == n - 1 && j == m - 1) continue;
                if(i + 1 < n) a = dp[i + 1][j];
                if(j + 1 < m) b = dp[i][j + 1];
                int t = min(a, b);
                if(t - dungeon[i][j] <= 0) dp[i][j] = 1;
                else dp[i][j] = t - dungeon[i][j];
            }
        }
        return dp[0][0];

        
    }
};