class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = nums;
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        int ans = nums[0];
        for(int i = 1; i < n; i++) {
            while(pq.size() && i - pq.top().second > k) pq.pop();
            dp[i] = max(dp[i], pq.top().first + nums[i]);
            ans = max(ans, dp[i]);
            pq.push({dp[i], i});
        }
        return ans;
    }
};