class Solution {
public:
    int fun(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mx = INT_MIN;
        for(int k = i; k <= j; k++) {
            mx = max(mx, nums[i - 1] * nums[k] * nums[j + 1] + fun(i, k - 1, nums, dp) + fun(k + 1, j, nums, dp));
        }
        return dp[i][j] = mx;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> v;
        v.push_back(1);
        for(int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
        }
        v.push_back(1);
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(1, n - 2, v, dp);
    }
};