class Solution {
public:
    bool fun(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        int n = s.size();
        int m = p.size();
        if(i == n) {
            while(j + 1 < m && p[j + 1] == '*') j += 2;
            return j >= m;
        }
        if(j == m) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(j + 1 < m && p[j + 1] == '*') {
            int a = 0;
            if(s[i] == p[j] || p[j] == '.') a = fun(i + 1, j, s, p, dp);
            int b = fun(i, j + 2, s, p, dp);
            int c = 0;
            if(s[i] == p[j] || p[j] == '.') c = fun(i + 1, j + 2, s, p, dp);
            return dp[i][j] = a || b || c;
        } else {
            if(s[i] == p[j] || p[j] == '.') return dp[i][j] = fun(i + 1, j + 1, s, p, dp);
            else return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(0, 0, s, p, dp);
    }
};