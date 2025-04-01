class Solution {
public:
    int fun(int n, vector<int>& nums, int i, vector<int>& dp) {
        if(i > n) return 0;
        if(i == n) return nums[n];
        if(dp[i] != -1) return dp[i];
        int a = 0, b = 0;
        a = nums[i] + fun(n, nums, i + 2, dp);
        b = fun(n, nums, i + 1, dp);
        return dp[i] = max(a, b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1), dp2(n, -1);
        return max(fun(n - 1, nums, 1, dp1), fun(n - 2, nums, 0, dp2));
    }
};