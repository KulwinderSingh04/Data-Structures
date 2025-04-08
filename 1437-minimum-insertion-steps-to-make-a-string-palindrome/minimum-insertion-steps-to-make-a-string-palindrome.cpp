class Solution {
public:
    int fun(int i1, int i2, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(text1[i1] == text2[i2]) return dp[i1][i2] = 1 + fun(i1 - 1, i2 - 1, text1, text2, dp);
        else return dp[i1][i2] = max(fun(i1 - 1, i2, text1, text2, dp), fun(i1, i2 - 1, text1, text2, dp));
    }
    int minInsertions(string s) {
        string s1 = s;
        int n = s.size(); 
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return n - fun(n - 1, n - 1, s1, s, dp);
    }
};