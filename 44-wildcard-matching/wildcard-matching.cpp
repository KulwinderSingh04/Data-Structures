class Solution {
public:
    bool fun(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if(i < 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false;
            }
            cout << "YES" << endl;
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
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(s, p, n - 1, m - 1, dp);
    }
};