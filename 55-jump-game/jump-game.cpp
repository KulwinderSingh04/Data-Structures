class Solution {
public:
    bool fun(int idx, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if(idx >= n - 1) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i = idx + 1; i <= idx + nums[idx]; i++) {
            bool f = fun(i, nums, dp);
            if(f) return dp[idx] = f;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fun(0, nums, dp);
    }
};