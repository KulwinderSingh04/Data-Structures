class Solution {
public:
    int fun(vector<int>& nums, int i, int pi, vector<vector<int>>& dp) {
        int n = nums.size();
        if(i == n - 1) {
            if(pi == -1 || nums[i] > nums[pi]) return 1;
            return 0;
        }
        if(pi != -1 && dp[i][pi] != -1) return dp[i][pi];
        int pick = 0;
        if(pi == -1 || nums[i] > nums[pi]) pick = 1 + fun(nums, i + 1, i, dp);
        int np = fun(nums, i + 1, pi, dp);
        return pi != -1 ? dp[i][pi] = max(np, pick) : max(np, pick);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(nums, 0, -1, dp);
    }
};