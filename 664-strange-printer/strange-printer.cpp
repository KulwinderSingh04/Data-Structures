class Solution {
public:
    int fun(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i == j) return 1;
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int k = i + 1;
        while(k <= j && s[k] == s[i]) k++;
        int a1 = 1 + fun(k, j, s, dp);
        int a2 = INT_MAX;
        for(int l = k; l <= j; l++) {
            if(s[l] == s[i]) {
                int ans = fun(k, l - 1, s, dp) + fun(l, j, s, dp);
                a2 = min(a2, ans);
            }
        }
        return dp[i][j] = min(a1,a2);
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(0, n - 1, s, dp);
    }
};