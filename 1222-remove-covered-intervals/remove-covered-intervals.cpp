class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int s = intervals[0][0];
        int e = intervals[0][1];
        int n = intervals.size();
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= s  && intervals[i][1] <= e) continue;
            s = intervals[i][0];
            e = intervals[i][1];
            cnt++;
        }
        return cnt;
    }
};