class Solution {
public:
    int fun(int i, vector<int>& nums, int k, int op1, int op2, vector<vector<vector<int>>>& dp) {
        int n = nums.size();
        if(i == n) {
            return 0;
        }
        if(dp[i][op1][op2] != -1) return dp[i][op1][op2];
        int a = 1e9, b = 1e9, c = 1e9, e = 1e9;
        if(op1 > 0) a = (nums[i] + 1) / 2 + fun(i + 1, nums, k, op1 - 1, op2, dp); 
        if(nums[i] - k >= 0 && op2 > 0) b = nums[i] - k + fun(i + 1, nums, k, op1, op2 - 1, dp); 
        if((nums[i] + 1) / 2 - k >= 0 && op1 > 0 && op2 > 0) c = (nums[i] + 1) / 2 - k + fun(i + 1, nums, k, op1 - 1, op2 - 1, dp);
        if(nums[i] - k >= 0 && op1 > 0 && op2 > 0) e = (nums[i] - k + 1) / 2 + fun(i + 1, nums, k, op1 - 1, op2 - 1, dp);
        int d = nums[i] + fun(i + 1, nums, k, op1, op2, dp);
        return dp[i][op1][op2] = min({a, b, c, d, e});
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (op1 + 1, vector<int> (op2 + 1, -1)));
        return fun(0, nums, k, op1, op2, dp);
    }
};