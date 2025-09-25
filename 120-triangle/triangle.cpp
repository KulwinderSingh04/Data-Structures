class Solution {
public:
    int fun(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        if(i == n) return 0;
        if(dp[i][j] != -1e6) return dp[i][j];
        int a = triangle[i][j] + fun(i + 1, j, triangle, dp);
        int b = triangle[i][j] + fun(i + 1, j + 1, triangle, dp);
        return dp[i][j] = min(a, b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1e6));
        return fun(0, 0, triangle, dp);
    }
};