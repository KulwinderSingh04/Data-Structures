class Solution {
public:
    int search(vector<vector<int>>& meetings, int x) {
        int n = meetings.size();
        int lo = 0;
        int hi = n - 1;
        int ans = n;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(meetings[mid][0] >= x) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
    long long fun(int i, int flag, vector<vector<int>>& meetings, vector<vector<long long>>& dp) {
        int n = meetings.size();
        if(i == n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int idx = search(meetings, meetings[i][1]);
        int start = meetings[i][1];
        if(idx != n) start = meetings[idx][0];
        // cout << idx << endl;
        long long take = meetings[i][2] + start - meetings[i][1] + fun(idx, 1, meetings, dp);
        int ns = meetings[i][0];
        if(i + 1 < n) ns = meetings[i + 1][0];
        int val = ns - meetings[i][0];
        if(flag == 0) val = 0;
        long long nt = val + fun(i + 1, flag, meetings, dp);
        return dp[i][flag] = max(take, nt);
    }
    long long maxEarnings(vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        vector<vector<long long>> dp(n, vector<long long> (2, -1));
        return fun(0, 0, meetings, dp);
    }
};