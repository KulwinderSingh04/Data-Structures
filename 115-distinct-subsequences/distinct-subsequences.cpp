class Solution {
public:
    int fun(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        int n = s.size();
        int m = t.size();
        if(j >= m) return 1;
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = 0;
        if(s[i] == t[j]) a = fun(s, t, i + 1, j + 1, dp); 
        int b = fun(s, t, i + 1, j, dp);
        return dp[i][j] = a + b;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fun(s, t, 0, 0, dp);
    }
};