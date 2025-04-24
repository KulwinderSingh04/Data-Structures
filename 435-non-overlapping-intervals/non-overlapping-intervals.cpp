bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int e = intervals[0][1];
        int count = 1;
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] >= e) {
                count++;
                e = intervals[i][1];
            }
        }
        return n - count;
    }
};