class Solution {
public:
    int fun(int i, int rem, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == nums.size()) return (rem == 0 ? 0 : -1e5);
        if(dp[i][rem] != -1) return dp[i][rem];
        int a = nums[i] + fun(i + 1, (rem + nums[i]) % 3, nums, dp);
        int b = fun(i + 1, rem, nums, dp);
        return dp[i][rem] = max(a, b);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return fun(0, 0, nums, dp);
    }
};