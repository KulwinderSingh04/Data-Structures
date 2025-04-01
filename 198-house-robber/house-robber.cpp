class Solution {
public:
    int fun(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        if(i < 0) return 0;
        if(i == 0) return nums[0];
        if(dp[i] != -1) return dp[i];
        int a = 0, b = 0;
        a = nums[i] + fun(nums, i - 2, dp);
        b = fun(nums, i - 1, dp);
        return dp[i] = max(a, b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fun(nums, n - 1, dp);
    }
};