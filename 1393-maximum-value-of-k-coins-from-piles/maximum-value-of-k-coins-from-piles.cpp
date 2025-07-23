class Solution {
public:
    int fun(int i, vector<vector<int>>& piles, int k, vector<vector<int>>& dp) {
        if(k == 0) return 0;
        if(i == piles.size()) return INT_MIN;
        
        if(dp[i][k] != -1) return dp[i][k];
        int p = INT_MIN;
        for(int j = 0; j < min(k, (int)piles[i].size()); j++) {
            p = max(p, piles[i][j] + fun(i + 1, piles, k - (j + 1), dp));
        }
        int np = fun(i + 1, piles, k, dp);
        return dp[i][k] = max(np, p);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < piles[i].size(); j++) {
                piles[i][j] += piles[i][j - 1];
            }
        }
        return fun(0, piles, k, dp);

    }
};