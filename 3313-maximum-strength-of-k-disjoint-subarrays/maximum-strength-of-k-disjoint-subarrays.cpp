class Solution {
public:
    long long fun(int i, int k, int start_new, vector<int>& nums, vector<vector<vector<long long>>>& dp) {
        if(k == 0) return 0;
        int n = nums.size();
        if(i == n) return -1e18;
        if(dp[i][k][start_new] != -1e18) return dp[i][k][start_new];
        long long not_take = LLONG_MIN;
        if(start_new) not_take = fun(i + 1, k, true, nums, dp);
        long long take = LLONG_MIN;
        if(k % 2) {
            take = 1LL * nums[i] * k + fun(i + 1, k, false, nums, dp);
            take = max(take, 1LL * nums[i] * k + fun(i + 1, k - 1, true, nums, dp));
        } else {
            take = 1LL * -nums[i] * k + fun(i + 1, k, false, nums, dp);
            take = max(take, 1LL * -nums[i] * k + fun(i + 1, k - 1, true, nums, dp));
        }
        return dp[i][k][start_new] = max(not_take, take);

    }
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (k + 1, vector<long long> (2, -1e18)));
        return fun(0, k, true, nums, dp);
    }
};