class Solution {
public:
    bool fun(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(i == -1) {
            while(j >= 0) {
                if(p[j] != '*') return false;
                j--;
            }
            return true;
        }
        if(j <= -1) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = fun(i - 1, j - 1, s, p, dp);
        }
        if(p[j] == '*') {
            bool a = fun(i - 1, j, s, p, dp);
            bool b = fun(i - 1, j - 1, s, p, dp);
            bool c = fun(i, j - 1, s, p, dp);
            return dp[i][j] = a || b || c;
        } else return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(n - 1, m - 1, s, p, dp);
    }
};