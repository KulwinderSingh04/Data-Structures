class Solution {
public:
    int fun(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mn = INT_MAX;
        for(int k = i; k <= j; k++) {
            int steps = cuts[j + 1] - cuts[i - 1] + fun(cuts, i, k - 1, dp) + fun(cuts, k + 1, j, dp);
            mn = min(mn, steps);
        }
        return dp[i][j] = mn;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int t = cuts.size();
        vector<vector<int>> dp(t, vector<int> (t, -1));
        return fun(cuts, 1, t - 2, dp);
    }
};