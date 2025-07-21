class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long long diff = 1LL * nums[i] - nums[j];
                int count_at_j = dp[j][diff];
                dp[i][diff] += count_at_j + 1;
                res += count_at_j;
            }
        }
        return res;
    }
};