class Solution {
public:
    int fun(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == j) return nums[i];
        if(i > j) return 0;
        int a = nums[i] + min(fun(i + 2, j, nums, dp), fun(i + 1, j - 1, nums, dp));
        int b = nums[j] + min(fun(i, j - 2, nums, dp), fun(i + 1, j - 1, nums, dp));

        return dp[i][j] = max(a, b);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for(auto x : nums) tot += x;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int a = fun(0, n - 1, nums, dp);
        return 2 * a >= tot;
    }
};