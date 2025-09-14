class Solution {
public:
    int MOD = 1e9 + 7;
    int fun(int i, int par, int t, vector<int>& nums, vector<vector<vector<long long>>>& dp) {
        int n = nums.size();
        if(i == n) {
            return 1;
        }
        if(par != -1 && dp[i][par][t] != -1) return dp[i][par][t];
        long long a = 0, b = 0;
        if(par == nums[i] % 2 && t < 2) a = fun(i + 1, par, t + 1, nums, dp);
        if(par != nums[i] % 2) b = fun(i + 1, nums[i] % 2, 1, nums, dp);
        long long c = fun(i + 1, par, t, nums, dp);
        if(par == -1) return (a + b + c) % MOD;
        return dp[i][par][t] = (a + b + c) % MOD;
    }
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (2, vector<long long> (3, -1)));
        return fun(0, -1, 0, nums, dp) - 1;
    }
};