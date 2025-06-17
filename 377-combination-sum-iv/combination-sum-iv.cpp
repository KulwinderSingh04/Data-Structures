class Solution {
public:
    int fun(int target, vector<int>& nums, vector<int>& dp) {
        if(target == 0) {
            return true;
        }
        if(dp[target] != -1) return dp[target];
        int a = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(target - nums[i] >= 0) a += fun(target - nums[i], nums, dp);
        }
        return dp[target] = a;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return fun(target, nums, dp);
    }
};