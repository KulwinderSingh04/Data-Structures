class Solution {
public:
    int MOD = 1e9 + 7;
    int fun(int i, int g, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();
        if(i == n) return g == 1;
        if(dp[i][g] != -1) return dp[i][g];
        long long res = 0;
        for(int j = 0; j < m; j++) {
            res = (res + fun(i + 1, __gcd(g, mat[i][j]), mat, dp)) % MOD;
        }
        return dp[i][g] = res;
    }
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int> (151, -1));
        return fun(0, 0, mat, dp);
    }
};