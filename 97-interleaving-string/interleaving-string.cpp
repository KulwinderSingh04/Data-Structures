class Solution {
public:
    bool fun(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp) {
        if(j == s2.size()) {
            return s3.substr(k) == s1.substr(i);
        }
        if(i == s1.size()) {
            return s3.substr(k) == s2.substr(j);
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        bool a = false, b = false;
        if(s1[i] == s3[k]) a = fun(i + 1, j, k + 1, s1, s2, s3, dp);
        if(s2[j] == s3[k]) b = fun(i, j + 1, k + 1, s1, s2, s3, dp);
        return dp[i][j][k] = a || b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<vector<int>>> dp(s1.size(), vector<vector<int>> (s2.size(), vector<int> (s3.size(), -1)));
        return fun(0, 0, 0, s1, s2, s3, dp);
    }
};