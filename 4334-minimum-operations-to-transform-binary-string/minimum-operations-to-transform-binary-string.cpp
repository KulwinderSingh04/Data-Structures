class Solution {
public:
    int fun(int i, string& s1, string& s2, vector<int>& dp) {
        int n = s1.size();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        if(s1[i] == s2[i]) return dp[i] = fun(i + 1, s1, s2, dp);
        if(s1[i] == '0') return dp[i] = 1 + fun(i + 1, s1, s2, dp);
        int ans = 1e9;
        if(i > 0) {
            ans = min(ans, 2 + fun(i + 1, s1, s2, dp));
        }
        if(i + 1 < n && s1[i + 1] == '1') {
            if(s2[i + 1] == '1') ans = min(ans, 2 + fun(i + 2, s1, s2, dp));
            else ans = min(ans, 1 + fun(i + 2, s1, s2, dp));
        }
        if(i + 1 < n && s1[i + 1] == '0') {
            if(s2[i + 1] == '1') ans = min(ans, 3 + fun(i + 2, s1, s2, dp));
            else ans = min(ans, 2 + fun(i + 2, s1, s2, dp));
        }
        // if(i > 0 && s2[i - 1] == '0') {
        //     ans = min(ans, 2 + fun(i + 1, s1, s2));
        // }
        return dp[i] =  ans;

    }
    int minOperations(string s1, string s2) {
        int n = s1.size();
        vector<int> dp(n, -1);
        int ans = fun(0, s1, s2, dp);
        return ans > 1e7 ? -1 : ans;
    }
};