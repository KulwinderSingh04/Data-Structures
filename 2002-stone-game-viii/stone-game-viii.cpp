class Solution {
public:
    int fun(int i, vector<int>& stones, vector<int>& dp) {
        int n = stones.size();
        if(i == n - 1) return stones[i];
        if(dp[i] != INT_MAX) return dp[i];
        int take = stones[i] - fun(i + 1, stones, dp);
        int skip = fun(i + 1, stones, dp);
        return dp[i] = max(take, skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n, INT_MAX);
        for(int i = 1; i < n; i++) stones[i] += stones[i - 1];
        return fun(1, stones, dp);
    }
};