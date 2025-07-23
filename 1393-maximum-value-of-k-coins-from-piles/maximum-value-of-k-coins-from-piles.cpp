class Solution {
public:
    // int fun(int i, vector<vector<int>>& piles, int k, vector<vector<int>>& dp) {
    //     if(k == 0) return 0;
    //     if(i == piles.size()) return INT_MIN;
        
    //     if(dp[i][k] != -1) return dp[i][k];
    //     int p = INT_MIN;
    //     for(int j = 0; j < min(k, (int)piles[i].size()); j++) {
    //         p = max(p, piles[i][j] + fun(i + 1, piles, k - (j + 1), dp));
    //     }
    //     int np = fun(i + 1, piles, k, dp);
    //     return dp[i][k] = max(np, p);
    // }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1));
        for(int j = 1; j <= k; j++) dp[n][k] = INT_MIN;
        for(int i = 0; i < n; i++) dp[i][0] = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= k; j++) {
                int p = INT_MIN;
                int sum = 0;
                for(int t = 0; t < min(j, (int)piles[i].size()); t++) {
                    sum += piles[i][t];
                    p = max(p, sum + dp[i + 1][j - (t + 1)]);
                }
                int np = dp[i + 1][j];
                dp[i][j] = max(np, p);
            }
        }

        return dp[0][k];

    }
};