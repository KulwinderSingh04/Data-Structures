class Solution {
public:
    long long fun(int i, int state, vector<int>& nums, int k, vector<vector<long long>>& dp) {
        int n = nums.size();
        if(i == n) return state == 0 ? LLONG_MIN : 0;
        if(state == 5) return 0;
        if(dp[i][state] != -1e18) return dp[i][state];
        long long ans = LLONG_MIN;
        if(state == 0) {
            ans = fun(i + 1, 0, nums, k, dp);
            ans = max(ans, nums[i] + fun(i + 1, 1, nums, k, dp));
            ans = max(ans, nums[i] / k + fun(i + 1, 2, nums, k, dp));
            ans = max(ans, 1LL * nums[i] * k + fun(i + 1, 3, nums, k, dp));
        } else if(state == 1) {
            ans = nums[i] / k + fun(i + 1, 2, nums, k, dp);
            ans = max(ans, 1LL * nums[i] * k + fun(i + 1, 3, nums, k, dp));
            ans = max(ans, nums[i] + fun(i + 1, 4, nums, k, dp));
            ans = max(ans, fun(i + 1, 5, nums, k, dp));
        } else if(state == 2) {
            ans = nums[i] / k + fun(i + 1, 2, nums, k, dp);
            ans = max(ans, nums[i] + fun(i + 1, 4, nums, k, dp));
            ans = max(ans, fun(i + 1, 5, nums, k, dp));
        } else if(state == 3) {
            ans = 1LL * nums[i] * k + fun(i + 1, 3, nums, k, dp);
            ans = max(ans, nums[i] + fun(i + 1, 4, nums, k, dp));
            ans = max(ans, fun(i + 1, 5, nums, k, dp));
        } else {
            ans = max(ans, nums[i] + fun(i + 1, 4, nums, k, dp));
            ans = max(ans, fun(i + 1, 5, nums, k, dp));
        }
        return dp[i][state] = ans;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long> (6, -1e18));
        return fun(0, 0, nums, k, dp);
    }
};