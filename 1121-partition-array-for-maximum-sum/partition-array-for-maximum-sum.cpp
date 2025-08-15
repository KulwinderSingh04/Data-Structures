class Solution {
public:
    int fun(int i, vector<int>& arr, int k, vector<int>& dp) {
        int n = arr.size();
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int mx = 0;
        int res = 0;
        for(int j = i; j < min(i + k, n); j++) {
            mx = max(mx, arr[j]);
            res = max(res, mx * (j - i + 1) + fun(j + 1, arr, k, dp));
        }
        return dp[i] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return fun(0, arr, k, dp);
    }
};