class Solution {
public:
    int fun(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if(i > j) return 0;
        int mx = 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i; k <= j; k++) {
            int a = nums[i - 1] * nums[k] * nums[j + 1] + fun(nums, i, k - 1, dp) + fun(nums, k + 1, j, dp);
            mx = max(mx, a);
        }
        return dp[i][j] = mx;
    }
    int maxCoins(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        nums.push_back(1);
        reverse(nums.begin(), nums.end());
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = n - 2; i >= 1; i--) {
            for(int j = i; j < n - 1; j++) {
                int mx = 0;
                for(int k = i; k <= j; k++) {
                    int a = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    mx = max(mx, a);
                }
                dp[i][j] = mx;
            }
        }
        return dp[1][n - 2];
    }
};