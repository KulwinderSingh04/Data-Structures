class Solution {
public:
    int MOD = 1e9+7;
    int fun(int r, int c, int k, vector<vector<int>>& pizza, vector<vector<vector<int>>>& dp) {
        int n = pizza.size();
        int m = pizza[0].size();
        // if(pizza[r][c] < k) return 0;
        if(k == 1) return pizza[r][c] >= 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        long long ans = 0;
        for(int i = r + 1; i < n; i++) {
            int applesUp = pizza[r][c] - pizza[i][c];
            if(applesUp >= 1 && pizza[i][c] >= k - 1) {
                ans += fun(i, c, k - 1, pizza, dp);
                ans %= MOD;
            }
        }

        for(int j = c + 1; j < m; j++) {
            int applesLeft = pizza[r][c] - pizza[r][j];
            if(applesLeft >= 1 && pizza[r][j] >= k - 1) {
                ans += fun(r, j, k - 1, pizza, dp);
                ans %= MOD;
            }
        }
        return dp[r][c][k] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        vector<vector<int>> v(n, vector<int> (m));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i + 1 < n) v[i][j] += v[i + 1][j];
                if(j + 1 < m) v[i][j] += v[i][j + 1];
                if(i + 1 < n && j + 1 < m) v[i][j] -= v[i + 1][j + 1];
                if(pizza[i][j] == 'A') {
                    v[i][j] += 1;
                }
            }
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(k + 1, -1)));
        return fun(0, 0, k, v, dp);
    }
};