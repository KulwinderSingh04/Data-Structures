class Solution {
public:
    int fun(int i, int j, vector<int>& stone, vector<vector<int>>& dp) {
        if(i >= j) return 0;
        int ans = 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i; k < j; k++) {
            int leftSum = stone[k];
            if(i > 0) leftSum -= stone[i - 1];
            int rightSum = stone[j] - stone[k];
            if(leftSum > rightSum) {
                ans = max(ans, rightSum + fun(k + 1, j, stone, dp));
            } else if(rightSum > leftSum) {
                ans = max(ans, leftSum + fun(i, k, stone, dp));
            } else {
                ans = max(ans, leftSum + fun(i, k, stone, dp));
                ans = max(ans, rightSum + fun(k + 1, j, stone, dp));
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for(int i = 1; i < n; i++) {
            stoneValue[i] += stoneValue[i - 1];
        }
        return fun(0, n - 1, stoneValue, dp);
    }
};