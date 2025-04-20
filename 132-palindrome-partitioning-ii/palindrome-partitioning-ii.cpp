class Solution {
public:
    bool isPal(string& s, int i, int j) {
        int n = s.size();
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
    int fun(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i > j) return 0;
        // if(i == j) return 0;
        int mn = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i; k <= j; k++) {
            int steps = INT_MAX;
            if(isPal(s, i, k)) {
                steps = 1 + fun(s, k + 1, j, dp);
                mn = min(mn, steps);
            }
        }
        return dp[i][j] = mn;
    }
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(s, 0, n - 1, dp) - 1;
    }
};