class Solution {
public:
    int fun(int i, int flag, string& s, vector<vector<int>>& dp) {
        int n = s.size();
        if(flag) {
            int ans = 0;
            for(int j = i; j < n; j++) ans += s[j] == '0';
            return ans;
        }
        if(i == n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        if(s[i] == '1') {
            int p = 1 + fun(i + 1, 0, s, dp);
            int np = fun(i + 1, 1, s, dp);
            return dp[i][flag] = min(np, p);
        } else {
            int p = 1 + fun(i + 1, 1, s, dp);
            int np = fun(i + 1, 0, s, dp);
            return dp[i][flag] = min(np, p);
        }

    }
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = dp[i + 1][1] + (s[i] == '0');
        }
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                dp[i][0] = min(1 + dp[i + 1][0], dp[i + 1][1]);
            } else {
                dp[i][0] = min(dp[i + 1][0], 1 + dp[i + 1][1]);
            }
        }
        return dp[0][0];
    }
};