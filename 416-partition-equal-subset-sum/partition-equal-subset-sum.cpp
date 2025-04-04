class Solution {
public:
    bool fun(vector<int>& nums, int i, int sum1, int sum2, vector<vector<int>>& dp) {
        int n = nums.size();
        if(sum1 / 2 == sum2) return true;
        if(sum1 / 2 < sum2) return false;
        if(i <= -1) return false;
        if(dp[i][sum2] != -1) return dp[i][sum2];
        bool a = fun(nums, i - 1, sum1, sum2 + nums[i], dp);
        bool b = fun(nums, i - 1, sum1, sum2, dp);
        return dp[i][sum2] = a || b;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) sum1 += nums[i];
        if(sum1 % 2 == 1) return false;
        vector<vector<int>> dp(n, vector<int> (sum1 / 2 + 1, -1));
        // for(int i = 0; i < n; i++) {
        //     for(int s = 0; s < sum1 / 2 + 1; s++){
        //         if(s == 0) dp[i][s] = true;
        //         else if(i == 0) {
        //             if(arr[i] == s) dp[i][s] = true;
        //             else dp[i][s] = false;
        //         }
        //         else {
        //             bool p = false;
        //             if(s - arr[i] >= 0) p = dp[i - 1][s - arr[i]];
        //             bool np = dp[i - 1][s];
        //             dp[i][s] = p || np;
        //         }
        //     }
        // }
        return fun(nums, n - 1, sum1, sum2, dp);
    }
};