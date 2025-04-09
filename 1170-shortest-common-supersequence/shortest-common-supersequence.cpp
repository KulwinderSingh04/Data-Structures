class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = n1, j = n2;
        string ans = "";
        while(i > 0 && j > 0) {
            if(text1[i - 1] == text2[j - 1]) {
                ans += text1[i - 1];
                i--;
                j--;
            }
            else {
                if(dp[i - 1][j] >= dp[i][j - 1]) {
                    ans += text1[i - 1];
                    i--;
                }
                else {
                    ans += text2[j - 1];
                    j--;
                }
            }
        }
        while(j-- > 0) ans.push_back(text2[j]);
        while(i-- > 0) ans.push_back(text1[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};