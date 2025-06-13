class Solution {
public:
    int fun(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(i == -1 && j == -1) {
            return 0;
        }
        if(i == -1) {
            return j + 1;
        }
        if(j == -1) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = fun(i - 1, j - 1, s1, s2, dp);
        else {
            int a = fun(i - 1, j - 1, s1, s2, dp);
            int b = fun(i - 1, j, s1, s2, dp);
            int c = fun(i, j - 1, s1, s2, dp);
            return dp[i][j] = 1 + min(a, min(b, c));
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return fun(n1 - 1, n2 - 1, word1, word2, dp);
    }
};