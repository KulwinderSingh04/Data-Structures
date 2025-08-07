class Solution {
public:
    int fun1(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp) {
        int n = fruits.size();
        if(i == n - 1 && j == n - 1) return 0;
        if(j <= i || j >= n) return INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k = j - 1; k <= j + 1; k++) {
            ans = max(ans, fruits[i][j] + fun1(i + 1, k, fruits, dp));
        }
        return dp[i][j] = ans;
    }
    int fun2(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>& dp) {
        int n = fruits.size();
        if(i == n - 1 && j == n - 1) return 0;
        if(i <= j || i >= n) return INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k = i - 1; k <= i + 1; k++) {
            ans = max(ans, fruits[i][j] + fun2(k, j + 1, fruits, dp));
        }
        return dp[i][j] = ans;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int tot = 0;
        for(int i = 0; i < n; i++) {
            tot += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>> dp1(n, vector<int> (n, -1));
        vector<vector<int>> dp2(n, vector<int> (n, -1));
        return tot + fun1(0, n - 1, fruits, dp1) + fun2(n - 1, 0, fruits, dp2);
    }
};