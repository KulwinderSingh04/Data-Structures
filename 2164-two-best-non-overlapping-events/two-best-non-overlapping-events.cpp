class Solution {
public:
    int fun(int i, int k, vector<int>& v, vector<vector<int>>& events, vector<vector<int>>& dp) {
        int n = events.size();
        if(i == n) return 0;
        if(k == 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int idx = upper_bound(v.begin(), v.end(), events[i][1]) - v.begin();
        int a = events[i][2] + fun(idx, k - 1, v, events, dp);
        int b = fun(i + 1, k, v, events, dp);
        return dp[i][k] = max(a, b);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<int> v(n);
        sort(events.begin(), events.end());
        for(int i = 0; i < n; i++) v[i] = events[i][0];
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return fun(0, 2, v, events, dp);
    }
};