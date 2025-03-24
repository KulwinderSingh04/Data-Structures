class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> ans;
        int n = meetings.size();
        for(int i = 0; i < n; i++) {
            if(i == 0 || ans.back()[1] < meetings[i][0]) ans.push_back(meetings[i]);
            else ans.back()[1] = max(ans.back()[1], meetings[i][1]);
        }
        int res = ans[0][0] - 1;
        for(int i = 1; i < ans.size(); i++) {
            cout << res << " ";
            res += ans[i][0] - ans[i - 1][1] - 1;
        }
        res += days - ans.back()[1];
        return res;
    }
};