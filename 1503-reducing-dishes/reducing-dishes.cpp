class Solution {
public:
    int fun(int i, int time, vector<int>& sat, vector<vector<int>>& dp) {
        int n = sat.size();
        if(i == n) return 0;
        if(dp[i][time] != -1) return dp[i][time];
        int p = time * sat[i] + fun(i + 1, time + 1, sat, dp);
        int np = fun(i + 1, time, sat, dp);
        return dp[i][time] = max(np, p);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return fun(0, 1, satisfaction, dp);
    }
};