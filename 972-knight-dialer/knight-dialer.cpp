class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    int fun(int i, int j, int n, vector<vector<vector<int>>>& dp) {
        if(i == 3 && j != 1) return 0;
        if(i < 0 || i >= 4 || j < 0 || j >= 3) return 0;
        if(n == 0) return 1;
        if(dp[i][j][n] != -1) return dp[i][j][n];
        long long res = 0;
        for(int k = 0; k < 8; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            res += fun(ni, nj, n - 1, dp);
            res %= MOD;
        }
        return dp[i][j][n] = res;
    }
    int knightDialer(int n) {
        vector<vector<vector<int>>> dp(4, vector<vector<int>> (3, vector<int> (n, -1)));
        int res = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == 3 && j != 1) continue;
                res += fun(i, j, n - 1, dp);
                res %= MOD;
            }
        }
        return res;
    }
};