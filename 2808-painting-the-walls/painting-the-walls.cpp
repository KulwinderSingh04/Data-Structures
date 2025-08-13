class Solution {
public:
    int fun(int i, int walls, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        if(walls <= 0) return 0;
        int n = cost.size();
        if(i == n) return 1e9;
        if(dp[i][walls] != -1) return dp[i][walls];
        int p = cost[i] + fun(i + 1, walls - 1 - time[i], cost, time, dp);
        int np = fun(i + 1, walls, cost, time, dp);
        return dp[i][walls] = min(p, np);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return fun(0, n, cost, time, dp);
    }
};