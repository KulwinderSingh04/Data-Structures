class Solution {
public:
    int fun(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(idx == n)  {
            return sum == 0;
        }  
        if(dp[idx][sum] != -1) return dp[idx][sum];
        long long a = 0;
        if(sum - nums[idx] >= 0) a = fun(idx, sum - nums[idx], nums, dp);
        long long b = fun(idx + 1,  sum, nums, dp);
        return dp[idx][sum] = a + b;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return fun(0, amount, coins, dp);
    }
};