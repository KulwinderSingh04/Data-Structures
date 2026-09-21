class Solution {
public:
    long long fun(int i, int pr, int rem, int k, vector<int>& nums, vector<vector<long long>>& dp) {
        int n = nums.size();
        long long ans = 0;
        if(pr == rem) ans++;
        if(i == n) return ans;
        if(dp[i][pr] != -1) return dp[i][pr];
        if(pr == k) {
            ans += fun(i + 1, nums[i] % k, rem, k, nums, dp);
            ans += fun(i + 1, pr, rem, k, nums, dp);
        } else {
            ans += fun(i + 1, 1LL * pr * nums[i] % k, rem, k, nums, dp);
        }
        return dp[i][pr] = ans;
    }
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans;
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            vector<vector<long long>> dp(n, vector<long long> (k + 1, -1));
            ans.push_back(fun(0, k, i, k, nums, dp));
        }
        return ans;
    }
};