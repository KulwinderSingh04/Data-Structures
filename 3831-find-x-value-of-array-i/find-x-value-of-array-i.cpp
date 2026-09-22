class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long> (k));
        
        for(int i = 0; i < n; i++) {
            dp[i][nums[i] % k]++;
            for(int rem = 0; rem < k; rem++) {
                if(i != 0) {
                    dp[i][1LL * nums[i] * rem % k] += dp[i - 1][rem];
                }
                
            }
        }
        vector<long long> ans(k);
        for(int rem = 0; rem < k; rem++) {
            for(int i = 0; i < n; i++) {
                ans[rem] += dp[i][rem];
            }
        }
        return ans;
    }
};