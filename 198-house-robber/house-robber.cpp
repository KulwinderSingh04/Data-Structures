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
        dp[0] = nums[0];
        if(n > 1) dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};