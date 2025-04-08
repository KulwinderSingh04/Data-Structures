class Solution {
public:
    int fun(int i1, int i2, string& text1, string& text2, vector<vector<int>>& dp) {
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(text1[i1] == text2[i2]) return dp[i1][i2] = 1 + fun(i1 - 1, i2 - 1, text1, text2, dp);
        else return dp[i1][i2] = max(fun(i1 - 1, i2, text1, text2, dp), fun(i1, i2 - 1, text1, text2, dp));
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size(); 
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return n1 + n2 - 2 * fun(n1 - 1, n2 - 1, word1, word2, dp);
    }
};