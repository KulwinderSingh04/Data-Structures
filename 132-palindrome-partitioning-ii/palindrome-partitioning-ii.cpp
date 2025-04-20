class Solution {
public:
    bool isPal(string& s, int i, int j) {
        int n = s.size();
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
    int fun(string& s, int i, int n, vector<int>& dp) {
        if(i == n) return 0;
        int mn = INT_MAX;
        if(dp[i] != -1) return dp[i];
        for(int k = i; k < n; k++) {
            int steps = INT_MAX;
            if(isPal(s, i, k)) {
                steps = 1 + fun(s, k + 1, n, dp);
                mn = min(mn, steps);
            }
        }
        return dp[i] = mn;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            int mn = INT_MAX;
            for(int k = i; k < n; k++) {
                int steps = INT_MAX;
                if(isPal(s, i, k)) {
                    steps = 1 + dp[k + 1];
                    mn = min(mn, steps);
                }
            }
            dp[i] = mn;
        }
        return dp[0] - 1;
    }
};