class Solution {
public:
    int fun(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        int n = triangle.size();
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = INT_MAX;
        int b = INT_MAX;
        a = triangle[i][j] + fun(triangle, i + 1, j, dp);
        if(j + 1 < triangle[i].size()) b = triangle[i][j + 1] + fun(triangle, i + 1, j + 1, dp);
        return dp[i][j] = min(a, b);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(triangle, 0, 0, dp);
    }
};