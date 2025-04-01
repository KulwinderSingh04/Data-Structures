class Solution {
public:
    long long fun(vector<vector<int>>& questions, int i, vector<long long>& dp) {
        int n = questions.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long pick = 0, nonPick = 0;
        pick = questions[i][0] + fun(questions, i + questions[i][1] + 1, dp);
        nonPick =fun(questions, i + 1, dp);
        return dp[i] = max(pick, nonPick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        dp[n - 1] = questions[n - 1][0];
        for(int i = n - 2; i >= 0; i--) {
            if(i + questions[i][1] + 1 < n) dp[i] = max(dp[i + 1], questions[i][0] + dp[i + questions[i][1] + 1]);
            else dp[i] = max(dp[i + 1],(long long)questions[i][0]);
        }
        return dp[0];
    }
};