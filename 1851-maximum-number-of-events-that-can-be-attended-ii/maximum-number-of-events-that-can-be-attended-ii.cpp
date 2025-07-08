class Solution {
public:
    int binSearch(vector<vector<int>>& nums, int target) {
        int lo = 0;
        int n = nums.size();
        int hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid][0] <= target) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
    int fun(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        int n = events.size();
        if(k == 0 || i == n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int p = 0;
        int j = binSearch(events, events[i][1]);
        p = events[i][2] + fun(j, events, k - 1, dp);
        int np = fun(i + 1, events, k, dp);
        return dp[i][k] = max(p, np);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        sort(events.begin(), events.end());
        return fun(0, events, k, dp);
    }
};