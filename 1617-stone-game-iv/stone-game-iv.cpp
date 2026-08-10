class Solution {
public:
    bool fun(int n, int alice, vector<vector<int>>& dp) {
        if(n == 0) return alice == 0;
        if(dp[n][alice] != -1) return dp[n][alice];
        if(alice) {
            for(int i = 1; i * i <= n; i++) {
                if(fun(n - i * i, !alice, dp)) return dp[n][alice] = true;
            }
            return dp[n][alice] = false;
        } else {
            for(int i = 1; i * i <= n; i++) {
                if(!fun(n - i * i, !alice, dp)) return dp[n][alice] = false;
            }
            return dp[n][alice] = true;
        }
    }
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return fun(n, 1, dp);
    }
};