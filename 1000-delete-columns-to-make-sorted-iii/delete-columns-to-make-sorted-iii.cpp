class Solution {
public:
    bool check(int j, int prev, vector<string>& strs) {
        // cout << j << " ";
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i][j] < strs[i][prev]) return false;
        }
        return true;
    }
    int fun(int i, int prev,vector<string>& strs, vector<vector<int>>& dp) {
        int n = strs[0].size();
        if(i == n) return 0;
        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev];
        int a = INT_MAX;
        if(prev == -1 || check(i, prev, strs)) {
            a = fun(i + 1, i, strs, dp);
        }
        int b = 1 + fun(i + 1, prev, strs, dp);
        return prev == -1 ? min(a, b) : dp[i][prev] = min(a, b);
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(0, -1, strs, dp);
    }
};