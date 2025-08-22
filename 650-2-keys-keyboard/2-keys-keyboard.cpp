class Solution {
public:
    int fun(int copy, int note, int flag, int n, vector<vector<int>>& dp) {
        if(note == n) return 0;
        if(note > n) return 1e8;
        if(dp[copy][note] != -1) return dp[copy][note];
        int a = 1e8;
        if(flag == 0) a = 1 + fun(note, note, 1, n, dp);
        int b = 1e8;
        if(copy != 0) b = 1 + fun(copy, note + copy, 0, n, dp);
        return dp[copy][note] = min(a, b);
    }
    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return fun(0, 1, 0, n, dp);
    }
};