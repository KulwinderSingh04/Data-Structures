class Solution {
public:
    int fun(int i, int target, vector<vector<int>>& q, int k, vector<vector<int>>& dp) {
        if(target == 0) return k;
        if(target < 0 || k >= q.size()) return INT_MAX;
        if(dp[target][k] != -1) return dp[target][k];
        int np = fun(i, target, q, k + 1, dp);
        int p = INT_MAX;
        if(q[k][0] <= i && i <= q[k][1]) p = fun(i, target - q[k][2], q, k + 1, dp);
        return dp[target][k] = min(p, np);
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int ans = -1;
        for(int i = 0; i < n; i++) {
            vector<vector<int>> dp(nums[i] + 1, vector<int> (q.size() + 1, -1));
            ans = max(ans, fun(i, nums[i], q, 0, dp));
        }
        return ans > q.size() ? -1 : ans;
    }
};