class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), count(n, 1);
        int idx = 0;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i]) {
                    if(dp[i] == dp[j] + 1) {
                        count[i] += count[j];
                    }
                    else if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
            mx = max(dp[i], mx);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) if(dp[i] == mx) ans += count[i];
        return ans;

    }
};