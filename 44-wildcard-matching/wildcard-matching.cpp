class Solution {
public:
    bool fun(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if(i < 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(j < 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return fun(s, p, i - 1, j - 1, dp);
        if(s[i] != p[j] && p[j] != '*') return false;
        bool a = fun(s, p, i - 1, j, dp);
        bool b = fun(s, p, i, j - 1, dp);
        return dp[i][j] = a || b;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        for(int j = 0; j <= m; j++) {
            for(int i = 1; i <= j; i++) {
                if(p[i - 1] != '*') {
                    dp[0][j] = false;
                    break;
                }
            }
            if(dp[0][j] == -1) dp[0][j] = true;
        }
        for(int i = 1; i < n + 1; i++) dp[i][0] = false;
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(s[i - 1] != p[j - 1] && p[j - 1] != '*') dp[i][j] = false;
                else {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};