class Solution {
public:
    int fun(int k, int n, vector<vector<int>>& dp) {
        if(n <= 0) return 0;
        if(k == 1) return n;
        if(dp[n][k] != -1) return dp[n][k];
        int low = 1, high = n, ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            int broken = fun(k - 1, mid - 1, dp);
            int notBroken = fun(k, n - mid, dp);

            int worst = 1 + max(broken, notBroken);
            ans = min(ans, worst);

            if (broken < notBroken)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return dp[n][k] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
        return fun(k, n, dp);
    }
};