class Solution {
public:
    bool fun(string& s, int i, int o, int c, vector<vector<vector<int>>>& dp) {
        int n = s.size();
        if(c > o) return false;
        
        if(i >= n) return c == o;
        if(dp[i][o][c] != -1) return dp[i][o][c];
        if(s[i] == '(') return dp[i][o][c] = fun(s, i + 1, o + 1, c, dp);
        else if(s[i] == ')') return dp[i][o][c] = fun(s, i + 1, o, c + 1, dp);
        else {
            bool x = fun(s, i + 1, o , c, dp);
            bool y = fun(s, i + 1, o + 1 , c, dp);
            bool z = fun(s, i + 1, o , c + 1, dp);
            return dp[i][o][c] = x || y || z;
        }
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n, -1)));
        return fun(s, 0, 0, 0, dp);
    }
};