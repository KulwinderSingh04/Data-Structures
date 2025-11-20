class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int n = intervals.size();
        int p1 = intervals[0][1] - 1;
        int p2 = intervals[0][1];
        int ans = 2;
        for(int i = 1; i < n; i++) {
            if (p1 >= intervals[i][0]) continue;
            if(p2 < intervals[i][0]) {
                p1 = intervals[i][1] - 1;
                p2 = intervals[i][1];
                ans += 2;
            }
            else {
                p1 = p2;
                p2 = intervals[i][1];
                ans++;
            }
        }
        return ans;
    }
};