class Solution {
public:
    bool fun(int mask, int k, int sum, int s, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(mask == (1 << (n)) - 1) {
            return k == 0;
        }
        if(k < 0) return false;
        if(dp[mask][k] != -1) return dp[mask][k];
        // cout << sum << endl;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;
            bool a = false;
            if(sum - nums[i] > 0) a = fun(mask | (1 << i), k, sum - nums[i], s, nums, dp);
            if(sum - nums[i] == 0) a = fun(mask | (1 << i), k - 1, s, s, nums, dp);
            if(a) return a;
        }
        return dp[mask][k] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp((1 << (n + 1)), vector<int> (k + 1, -1));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) return 0;
        sum /= k;
        return fun(0, k, sum, sum, nums, dp);
    }
};