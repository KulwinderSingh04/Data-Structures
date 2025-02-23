class Solution {
public:
    bool fun(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(j == -1 && i == -1 ) {
            return true ;
        } 
        if(j == -1 && i >= 0) return false;
        if(j >= 0 && i == -1) {
            for(int k = j; k >= 0; k--) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = fun(i - 1, j - 1, s, p, dp);
        if(p[j] == '*') {
            bool a = fun(i - 1, j, s, p, dp);
            bool b = fun(i, j - 1, s, p, dp);
            return dp[i][j] = a || b;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int i = s.size() - 1;
        int j = p.size() - 1;
        vector<vector<int>> dp(s.size(), vector<int> (p.size(), -1));
        return fun(i, j, s, p, dp);
    }
};