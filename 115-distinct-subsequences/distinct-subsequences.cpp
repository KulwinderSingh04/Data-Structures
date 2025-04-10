class Solution {
public:
    int fun(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        int n = s.size();
        int m = t.size();
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0;
        if(s[i] == t[j]) a = fun(s, t, i - 1, j - 1, dp); 
        int b = fun(s, t, i - 1, j, dp);
        return dp[i][j] = a + b;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long> (m + 1, 0));
        for(int i = 0;  i < n; i++) dp[i][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                unsigned long long a = 0;
                if(s[i - 1] == t[j - 1]) a = dp[i - 1][j - 1]; 
                unsigned long long b = dp[i - 1][j];
                dp[i][j] = a + b;
            }
        }
        return dp[n][m];
    }
};