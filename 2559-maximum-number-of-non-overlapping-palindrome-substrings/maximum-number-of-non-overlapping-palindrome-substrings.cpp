class Solution {
public:
    int fun(int i, int k, string& s, vector<vector<int>>& isPal, vector<int>& dp) {
        int n = s.size();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j = i + k - 1; j < n; j++) {
            if(isPal[i][j]) {
                ans = max(ans, 1 + fun(j + 1, k, s, isPal, dp));
            }
        }
        ans = max(ans, fun(i + 1, k, s, isPal, dp));
        return dp[i] = ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> isPal(n, vector<int> (n, -1));
        for(int i = 0; i < n; i++) isPal[i][i] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    if(j - i == 1) isPal[i][j] = 1; 
                    else isPal[i][j] = isPal[i + 1][j - 1];
                } else {
                    isPal[i][j] = 0;
                }
            }
        }
        vector<int> dp(n, -1);
        return fun(0, k, s, isPal, dp);
    }
};