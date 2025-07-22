class Solution {
public:
    int fun(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        int n = days.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int res = INT_MAX;
        for(int j = 0; j < 3; j++) {
            int idx;
            if(j == 0) idx = lower_bound(days.begin(), days.end(), days[i] + 1) - days.begin();
            else if(j == 1) idx = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();
            else  idx = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();
            // cout << idx << " ";
            res = min(res, costs[j] + fun(idx, days, costs, dp));
        }
        return dp[i] = res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return fun(0, days, costs, dp);
    }
};