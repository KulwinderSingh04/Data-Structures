class Solution {
public:
    int fun(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(i == s.size()) {
            return j == t.size();
        }
        if(j == t.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) {
            int a = fun(i + 1, j + 1, s, t, dp);
            int b = fun(i + 1, j, s, t, dp);
            return dp[i][j] = a + b;
        }
        int a = fun(i + 1, j, s, t, dp);
        return dp[i][j] = a;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(0, 0, s, t, dp);
    }
};