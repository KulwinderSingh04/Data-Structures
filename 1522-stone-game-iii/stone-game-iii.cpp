class Solution {
public:
    int fun(int i, int turn, vector<int>& stone, vector<vector<int>>& dp) {
        int n = stone.size();
        if(i == n) return 0;
        if(dp[i][turn] != -1e7) return dp[i][turn];
        int sum = 0;
        if(turn == 0) {
            int ans = stone[i] + fun(i + 1, !turn, stone, dp);
            if(i + 1 < n) ans = max(ans, stone[i] + stone[i + 1] + fun(i + 2, !turn, stone, dp));
            if(i + 2 < n) ans = max(ans, stone[i] + stone[i + 1] + stone[i + 2] + fun(i + 3, !turn, stone, dp));
            return dp[i][turn] = ans;
        } else {
            int ans = -stone[i] + fun(i + 1, !turn, stone, dp);
            if(i + 1 < n) ans = min(ans, -(stone[i] + stone[i + 1]) + fun(i + 2, !turn, stone, dp));
            if(i + 2 < n) ans = min(ans, -(stone[i] + stone[i + 1] + stone[i + 2]) + fun(i + 3, !turn, stone, dp));
            return dp[i][turn] = ans;
        }
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int> (2, -1e7));
        int t = fun(0, 0, stoneValue, dp);
        return t > 0 ? "Alice" : (t == 0 ? "Tie" : "Bob");
    }
};