class Solution {
public:
    int fun(int i, int d, vector<int>& job, vector<vector<int>>& dp) {
        int n = job.size();
        if(i == n) return 1e7;
        if(d == 1) {
            int ans = 0;
            for(int j = i; j < n; j++) ans = max(ans, job[j]);
            return ans;
        }
        if(dp[i][d] != -1) return dp[i][d];
        int a = 0;
        int t = 1e7;
        for(int j = i; j < n; j++) {
            a = max(a, job[j]);
            t = min(t, a + fun(j + 1, d - 1, job, dp));
        }
        return dp[i][d] = t;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n, vector<int> (d + 1, -1));
        return fun(0, d, jobDifficulty, dp);
    }
};