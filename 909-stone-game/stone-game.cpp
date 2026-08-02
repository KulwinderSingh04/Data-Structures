class Solution {
public:
    long long fun(int i, int j, int turn, vector<int>& nums, vector<vector<long long>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1e17) return dp[i][j];
        if(turn) {
            long long a = -1e16;
            a = max(a, nums[i] + fun(i + 1, j, !turn, nums, dp));
            a = max(a, nums[j] + fun(i, j - 1, !turn, nums, dp));
            return dp[i][j] = a;
        } else {
            long long a = 1e16;
            a = min(a, -nums[i] + fun(i + 1, j, !turn, nums, dp));
            a = min(a, -nums[j] + fun(i, j - 1, !turn, nums, dp));
            return dp[i][j] = a;
        }
    }
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long> (n, -1e17));
        return fun(0, n - 1, 1, nums, dp) >= 0;
    }
};