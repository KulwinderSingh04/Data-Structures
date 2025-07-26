class Solution {
public:
    int fun(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        int n = cuts.size();
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mx = INT_MAX;
        for(int k = i; k <= j; k++) {
            int left = fun(i, k - 1, cuts, dp);
            int right = fun(k + 1, j, cuts, dp);
            mx = min(mx, cuts[j + 1] - cuts[i - 1] + left + right);
        }
        return dp[i][j] = mx;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int n1 = cuts.size();
        vector<vector<int>> dp(n1, vector<int> (n1, -1));
        return fun(1, n1 - 2, cuts, dp);
    }
};