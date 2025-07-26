class Solution {
public:
    int fun(int i, vector<int>& piles, int m, int flag, vector<vector<vector<int>>>& dp) {
        int n = piles.size();
        if(i == n) return 0;
        if(dp[i][m][flag] != -1) return dp[i][m][flag];
        int p;
        if(flag) p = 0;
        else p = INT_MAX;
        int sum = 0;
        for(int j = i; j < min(n, i + 2 * m); j++) {
            sum += piles[j];
            int t = fun(j + 1, piles, max(m, j - i + 1), !flag, dp);
            if(flag == 1) p = max(sum + t, p);
            else p = min(p, t);
        }
        return dp[i][m][flag] = p;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (250, vector<int> (2, -1)));
        return fun(0, piles, 1, 1, dp);
    }
};