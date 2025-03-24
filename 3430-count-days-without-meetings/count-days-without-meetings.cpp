class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> ans = meetings[0];
        int n = meetings.size();
        int res = meetings[0][0] - 1;
        for(int i = 1; i < n; i++) {
            if(ans[1] < meetings[i][0]) {
                res += meetings[i][0] - ans[1] - 1;
                ans = meetings[i];
            }
            else ans[1] = max(ans[1], meetings[i][1]);
        }
        res += days - ans[1];
        return res;
    }
};