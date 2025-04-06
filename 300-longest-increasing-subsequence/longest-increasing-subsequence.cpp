class Solution {
public:
    int fun(vector<int>& nums, int i, int pi, vector<vector<int>>& dp) {
        int n = nums.size();
        if(i == n - 1) {
            if(pi == -1 || nums[pi] < nums[i]) return 1;
            return 0;
        }
        if(pi != -1) if(dp[i][pi] != -1) return dp[i][pi];
        int p = 0;
        if(pi == -1 || nums[pi] < nums[i]) p = 1 + fun(nums, i + 1, i, dp);
        int np = fun(nums, i + 1, pi, dp);
        if(pi != -1) dp[i][pi] = max(p, np);
        return max(p, np);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(nums, 0, -1, dp);
    }
};