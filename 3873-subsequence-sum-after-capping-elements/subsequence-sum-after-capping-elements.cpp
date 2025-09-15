class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int> (k + 1));
        for(int i = 0; i < n; i++) dp[i][0] = 1;
        for(int i = 1; i < k + 1; i++) if(nums[0] == i) dp[0][i] = 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < k + 1; j++) {
                int a = 0, b = 0;
                a = dp[i - 1][j];
                if(j - nums[i] >= 0) b = dp[i - 1][j - nums[i]];
                dp[i][j] = a || b;
            }
        }
        vector<bool> ans(n);
        for(int cap = 1; cap <= n; cap++) {
            int idx = lower_bound(nums.begin(), nums.end(), cap) - nums.begin();
            for(int tar = idx; tar <= n; tar++) {
                int p = tar - idx;
                if(k - p * cap == 0 || (k - p * cap >= 0 && idx > 0 && dp[idx - 1][k - p * cap])) {
                    ans[cap - 1] = true;
                    break;
                }
            }
        }
        return ans;
    }
};