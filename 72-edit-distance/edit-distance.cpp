class Solution {
public:
    int fun(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = fun(s, t, i - 1, j - 1, dp);
        int x = 1 + fun(s, t, i, j - 1, dp);
        int y = 1 + fun(s, t, i - 1, j, dp);
        int z = 1 + fun(s, t, i - 1, j - 1, dp);
        return dp[i][j] = min(x, min(y, z));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int i = 0; i <= m; i++) dp[0][i] = i;
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j  < m + 1; j++) {
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
        return dp[n][m];
    }
};