class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k, vector<int> (n, 1));
        int ans = 1;
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                int mod = (nums[prev] + nums[i]) % k;
                dp[mod][i] = max(dp[mod][i], dp[mod][prev] + 1);
                ans = max(ans, dp[mod][i]);
            }
        }
        return ans;
    }
};