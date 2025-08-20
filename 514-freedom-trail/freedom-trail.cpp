class Solution {
public:
    int fun(int i, int j, string& ring, string& key, vector<vector<int>>& dp) {
        int n = ring.size();
        if(j == key.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 1e7;
        for(int k = 0; k < n; k++) {
            if(ring[k] == key[j]) {
                int d1 = abs(i - k);
                int d2 = n - d1;
                res = min(res, min(d1, d2) + 1 + fun(k, j + 1, ring, key, dp));
            }
        }
        return dp[i][j] = res;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(0, 0, ring, key, dp);
    }
};