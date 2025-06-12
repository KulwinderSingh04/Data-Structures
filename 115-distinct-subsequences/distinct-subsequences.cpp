class Solution {
public:
    // int fun(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    //     if(i == -1) {
    //         return j == -1;
    //     }
    //     if(j == -1) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == t[j]) {
    //         int a = fun(i - 1, j - 1, s, t, dp);
    //         int b = fun(i - 1, j, s, t, dp);
    //         return dp[i][j] = a + b;
    //     }
    //     int a = fun(i - 1, j, s, t, dp);
    //     return dp[i][j] = a;
    // }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector< unsigned long long>> dp(n + 1, vector< unsigned long long> (m + 1, 0));
        // for(int )
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    unsigned long long a = dp[i - 1][j - 1];
                    unsigned long long b = dp[i - 1][j];
                    dp[i][j] = a + b;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};