class Solution {
public:
    int fun(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return s1[i] + fun(i + 1, j + 1, s1, s2, dp);
        int a = fun(i + 1, j, s1, s2, dp);
        int b = fun(i, j + 1, s1, s2, dp);
        return dp[i][j] = max(a, b);
    }
    int minimumDeleteSum(string s1, string s2) {
        int t = 0;
        for(auto x : s1) t += x;
        for(auto x : s2) t += x;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        cout << fun(0, 0, s1,s2, dp);
        return t - 2 * fun(0, 0, s1,s2, dp);
    }
};