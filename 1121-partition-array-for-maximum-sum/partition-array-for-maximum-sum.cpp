class Solution {
public:
    int fun(vector<int>& arr, int i, int k, vector<int>& dp) {
        int n = arr.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        int mx = 0;
        for(int t = i; t < min(n, i + k); t++) {
            mx = max(mx, arr[t]);
            int step = mx * (t - i + 1) + fun(arr, t + 1, k, dp);
            ans = max(step, ans);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return fun(arr, 0, k, dp);
    }
};