class Solution {
public:
    int fun(vector<int>& nums, int i, int target, map<int, map<int, int>>& dp) {
        if(i == 0) {
            if(target - nums[i] == 0 && target + nums[i] == 0) return 2;
            if(target - nums[i] == 0 || target + nums[i] == 0) return 1;
            return 0;
        }
        if(dp.find(i) != dp.end() && dp[i].find(target) != dp[i].end()) return dp[i][target]; 
        int add = fun(nums, i - 1, target + nums[i], dp);
        int sub = fun(nums, i - 1, target - nums[i], dp);
        return dp[i][target] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, map<int, int>> dp;
        return fun(nums, n - 1, target, dp);
    }
};