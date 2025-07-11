class Solution {
public:
    int fun(int i, int mx, vector<vector<int>>& intervals, map<pair<int, int>, int>& dp) {
        int n = intervals.size();
        if(i == n) {
            if(mx >= n - 1) return 0;
            return 1e9;
        }
        if(mx < intervals[i][0]) return 1e9;
        if(dp.find({i, mx}) != dp.end()) return dp[{i, mx}];
        int p = 1 + fun(i + 1,max(mx, intervals[i][1]), intervals, dp);
        int np = fun(i + 1, mx, intervals, dp);
        return dp[{i, mx}] = min(p, np);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals(n + 1);
        for(int i = 0; i < n + 1; i++) {
            int lo = max(0, i - ranges[i]);
            int hi = min(n, i + ranges[i]);
            intervals[i] = {lo, hi};
        }
        sort(intervals.begin(), intervals.end());
        map<pair<int, int>, int> dp;
        int t = fun(0, 0, intervals, dp);
        return t == 1e9 ? -1 : t;
    }
};