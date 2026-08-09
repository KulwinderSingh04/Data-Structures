class Solution {
public:
    int fun(int i, int turn, int m, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        int n = piles.size();
        if(i == n) return 0;
        int sum = 0;
        int ans = 0;
        if(dp[i][turn][m] != -1) return dp[i][turn][m];
        if(turn == 1) ans = 1e9;
        if(turn == 0) {
            // int ans = 0;
            for(int j = i; j < min(n, i + 2 * m); j++) {
                int x = j - i + 1;
                sum += piles[j];
                ans = max(ans, sum + fun(j + 1, !turn, max(m, x), piles, dp));
            }
        } else {
            // int ans = 1e9;
            for(int j = i; j < min(n, i + 2 * m); j++) {
                int x = j - i + 1;
                sum += piles[j];
                ans = min(ans, fun(j + 1, !turn, max(m, x), piles, dp));
            }
        }
        return dp[i][turn][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (500, -1)));
        return fun(0, 0, 1, piles, dp);
    }
};