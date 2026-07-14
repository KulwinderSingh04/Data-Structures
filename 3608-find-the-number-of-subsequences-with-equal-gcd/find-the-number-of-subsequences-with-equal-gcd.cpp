class Solution {
public:
    int MOD = 1e9 + 7;
    int fun(int i, int g1, int g2, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        int n = nums.size();
        if(i == n) return g1 == g2;
        if(dp[i][g1][g2] != -1) return dp[i][g1][g2];
        long long a = fun(i + 1, __gcd(g1, nums[i]), g2, nums, dp);
        a %= MOD;
        a += fun(i + 1, g1, __gcd(g2, nums[i]), nums, dp);
        a %= MOD;
        a += fun(i + 1, g1, g2, nums, dp);
        a %= MOD;
        return dp[i][g1][g2] = a % MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (201, vector<int> (201, -1)));
        return fun(0, 0, 0, nums, dp) - 1;
    }
};