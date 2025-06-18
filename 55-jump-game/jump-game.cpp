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
        vector<int> dp(n, 0);
        dp[n - 1] = 1;
        for(int  i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j <= min(n - 1, i + nums[i]); j++) {
                if(dp[j]) {
                    dp[i] = dp[j];
                    break;
                }
            }
        }
        return dp[0];
    }
};